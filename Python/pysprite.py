from pygame import *
import os, re, sys

class TempClass:
    """Temporary class used to generate sprite.database"""
    class Stub:
        def __init__(self):
            pass
    RE_FILE = re.compile(r'file=([^ ]+)') #pattern for file name in directory entry
    RE_SIZE = re.compile(r'size=([^ ]+)') #pattern for size in directory entry
    RE_DELAY = re.compile(r'delay=([^ ]+)') #pattern for delay in directory entry
    RE_COLORKEY = re.compile(r'colorkey=([^ ]+)') #pattern for colorkey in directory entry
    RE_NAME = re.compile(r'name=([^ ]+)') #pattern for name in directory entry
    RE_SHIFT = re.compile(r'shift=([^ ]+)') #pattern for shift in directory entry
    RE_NUMBER = re.compile(r'[0-9]+') #pattern for finding numbers
    def __init__(self):
        self.dict = {}
    def addsprite(self, sprite_name):
        self.dict[sprite_name] = {}

        #open directory for this sprite's animations
        f = open(os.path.join(sys.path[0], r'sprites', sprite_name, r'directory.txt'), 'r+')
        entries = f.read().split('\n')
        f.close()

        #generate sprite.database entry
        for entry in entries:
            #get strings for file_name, name, size, delay, and colorkey
            file_name = self.RE_FILE.search(entry).groups()[0]
            size = self.RE_SIZE.search(entry).groups()[0]
            delay = self.RE_DELAY.search(entry).groups()[0]
            colorkey = self.RE_COLORKEY.search(entry).groups()[0]
            name = self.RE_NAME.search(entry).groups()[0]
            shift = self.RE_SHIFT.search(entry).groups()[0]

            #convert size to tuple
            size = self.RE_NUMBER.findall(size)
            for i in xrange(len(size)):
                size[i] = int(size[i])
            size = tuple(size)

            #convert delay to tuple
            delay = self.RE_NUMBER.findall(delay)
            for i in xrange(len(delay)):
                delay[i] = int(delay[i])
            delay = tuple(delay)

            #convert colorkey to tuple
            colorkey = self.RE_NUMBER.findall(colorkey)
            for i in xrange(len(colorkey)):
                colorkey[i] = int(colorkey[i])
            colorkey = tuple(colorkey)

            #convert shift to tuple
            shift = self.RE_NUMBER.findall(shift)
            for i in xrange(len(shift)):
                shift[i] = int(shift[i])
            shift = tuple(shift)

            #generate sprite.database entry
            tempsurf = image.load(os.path.join(sys.path[0], r'sprites', sprite_name, file_name)).convert()
            tempsurf.set_colorkey(colorkey, RLEACCEL)
            multi = tempsurf.get_width() / size[0]
            l = []
            for i in xrange(multi):
                l.append(tempsurf.subsurface([(size[0]*i,0),size]))
            self.dict[sprite_name][name] = self.Stub()
            self.dict[sprite_name][name].surfs = tuple(l)
            self.dict[sprite_name][name].delay = delay
            self.dict[sprite_name][name].shift = shift
            
    def removesprite(self, sprite_name):
        del self.dict[sprite_name]

    def empty(self):
        self.dict = {}
        
sprite.database = TempClass() #setup sprite.database
TempClass.__name__ = 'sprite.Database'
del TempClass #Remove TempClass reference

#Change reference to basic sprite class to sprite.SpriteBase
sprite.SpriteBase = sprite.Sprite
sprite.SpriteBase.init = sprite.SpriteBase.__init__
class TempClass (sprite.SpriteBase):
    """This class will serve as a more usefull sprite class."""
    #ALIGNER will serve to speed up alignment.
    ALIGNER = {}
    def midbottom(self, point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(midbottom=point)
    ALIGNER['midbottom'] = midbottom
    del midbottom
    def midtop(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(midtop=point)
    ALIGNER['midtop'] = midtop
    del midtop
    def midleft(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(midleft=point)
    ALIGNER['midleft'] = midleft
    del midleft
    def midright(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(midright=point)
    ALIGNER['midright'] = midright
    del midright
    def center(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(center=point)
    ALIGNER['center'] = center
    del center
    def bottomleft(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(bottomleft=point)
    ALIGNER['bottomleft'] = bottomleft
    del bottomleft
    def bottomright(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(bottomright=point)
    ALIGNER['bottomright'] = bottomright
    del bottomright
    def topright(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(topright=point)
    ALIGNER['topright'] = topright
    del topright
    def topleft(self,point):
        self.rect = sprite.database.dict[self.sprite_name][self.seq_name].surfs[0].get_rect(topleft=point)
    ALIGNER['topleft'] = topleft
    del topleft

    RE_ALIGNMENT = re.compile(r'(.+)[=](.+)') #pattern for parsing alignment
    def __init__(self, sprite_name, seq_name, alignment, repititions=1):
        """self.__init__(str, str, str, [int]) -> Sprite
        Generates a sprite instance.
        Repititions value is meaningless while sprite is locked.
        Sprites are initially locked."""
        self.init()
        self.sprite_name = sprite_name
        self.seq_name = seq_name
        self.delay_count = 0
        self.seq_count = 0
        self.repititions = repititions
        self.rep_count = 0
        self.locked = True
        self.templocked = False
        self.seq_history = []

        #prepare to get rect
        align_by, point = self.RE_ALIGNMENT.match(alignment).groups()

        #convert point to tuple
        point = sprite.database.RE_NUMBER.findall(point)
        for i in xrange(len(point)):
            point[i] = int(point[i])
        point = tuple(point)

        #get rect
        self.ALIGNER[align_by](self,point)
    
    def update(self):
        """self.update() -> None
        This updates the sequence information for the sprite."""
        temp = sprite.database.dict[self.sprite_name][self.seq_name] #sprite database sequence entry
        self.delay_count = (self.delay_count+1)%temp.delay[self.seq_count] #update delay_count
        if self.delay_count == 0:
            self.seq_count = (self.seq_count+1)%len(temp.surfs) #update seq_count
            if self.seq_count == 0 and (not self.locked or self.templocked):
                self.rep_count = (self.rep_count+1)%self.repititions #update rep_count
                if self.rep_count == 0 and self.seq_history != []:   
                    self.locked = True
                    self.set_seq(self.seq_history.pop(0)) #fall back to seq from seq_history
                    self.unlock()

    def draw(self, surf, topleft=(0,0)):
        """self.draw(surface, [tuple]) -> None
        topleft is the topleft of the surface to be blitted upon with
        respect to the surface the sprite is spaced upon."""
        surf.blit(sprite.database.dict[self.sprite_name][self.seq_name].surfs[self.seq_count], (self.rect[0]-topleft[0],self.rect[1]-topleft[1],self.rect[2],self.rect[3]))

    def clear(self, surf, background, topleft=(0,0)):
        """self.clear(surface, surface, [tuple]) -> None
        topleft is the topleft of the surface to be blitted upon with
        respect to the surface the sprite is spaced upon."""
        surf.blit(background,(self.rect[0]-topleft[0],self.rect[1]-topleft[1],self.rect[2],self.rect[3]),self.rect)

    def fill(self, surf, color, topleft=(0,0)):
        """self.fill(surface, tuple, [tuple]) -> None
        topleft is the topleft of the surface to be at least partially
        filled with respect to the surface the sprite is spaced upon."""
        surf.fill(color, (self.rect[0]-topleft[0],self.rect[1]-topleft[1],self.rect[2],self.rect[3]))

    def collidepoint(self, point, topleft=(0,0)):
        """self.collidepoint(tuple, [tuple]) -> Bool
        topleft is the topleft of the surface corresponding to the point
        with respect to the surface the sprite is spaced upon."""
        return self.rect.collidepoint((point[0]+topleft[0],point[1]+topleft[1]))

    def colliderect(self, rect, topleft=(0,0)):
        """self.colliderect(rect, [tuple]) -> Bool
        topleft is the topleft of the suface corresponding the the rect
        with respect to the suface the sprite is spaced upon."""
        return self.rect.colliderect((rect[0]+topleft[0],rect[1]+topleft[1],rect[2],rect[3]))

    def set_seq(self, seq_name, repititions=1):
        """self.set_seq(str, [int]) -> None
        Sets sprite's sequence to seq_name.
        Repititions value is meaningless while sprite is locked.
        Sprites are initially locked."""
        #if sprite isn't locked insert old seq_nam into seq_history
        if not self.locked:
            self.seq_history.insert(0,self.seq_name)

        #set up new sequence information
        self.seq_name = seq_name
        self.delay_count = 0
        self.seq_count = 0
        self.repititions = repititions

        #adjust rect according to shift
        shift = sprite.database.dict[self.sprite_name][self.seq_name].shift
        self.rect[0] += shift[0]
        self.rect[1] += shift[1]
        self.rect[2] += shift[2]
        self.rect[3] += shift[3]

    def lock(self):
        """self.lock() -> None
        This prevents sprite to falling back to seqences from its sequence history and
        prevents sequences to be automatically saved to its history."""
        self.locked = True
        self.templocked = False

    def unlock(self):
        """self.unlock() -> None
        This allows sprite to fall back to sequences from its sequence history and
        allows sequences to be automatically saved to its history."""
        self.locked = False
        self.templocked = False

    def templock(self):
        """self.templock() -> None
        This locks the sprite until its current repitition sequence is finished."""
        self.locked = True
        self.templocked = True

    def align(self, alignment):
        """self.align(str) -> None
        Aligns sprite according to alignment string"""
        #prepare to get rect
        align_by, point = self.RE_ALIGNMENT.match(alignment).groups()

        #convert point to tuple
        point = sprite.database.RE_NUMBER.findall(point)
        for i in xrange(len(point)):
            point[i] = int(point[i])
        point = tuple(point)

        #get rect
        self.ALIGNER[align_by](self,point)
        
        self.ALIGNER[align_by](self,point)

sprite.Sprite = TempClass #Sprite class will be accessed through sprite.Sprite
TempClass.__name__ = 'sprite.Sprite'
del TempClass #Remove TempClass reference

sprite.GroupBase = sprite.Group #sprite.GroupBase refers to original sprite.Group
class TempClass(sprite.GroupBase):
    """This class will serve as a more useful group class."""
    def draw(self, surf, topleft=(0,0)):
        """self.draw(surface, [tuple]) -> None
        Calls the draw method for all sprites in group."""
        for temp in self:
            temp.draw(surf, topleft)

    def clear(self, surf, background, topleft=(0,0)):
        """self.clear(surface, surface, [tuple]) -> None
        Calls the clear method for all sprites in group."""
        for temp in self:
            temp.clear(surf, background, topleft)

    def fill(self, surf, color, topleft=(0,0)):
        """self.fill(surface, tuple, [tuple]) -> None
        Calls the fill method for all sprites in group."""
        for temp in self:
            temp.fill(surf, color, topleft)

    def collidepoint(self, point, topleft=(0,0)):
        """self.collidepoint(tuple, [tuple]) -> list
        Calls the collidepoint method for all sprites in group.
        Returns a list of all sprites that return True."""
        l = []
        for temp in self:
            if temp.collidepoint(point, topleft):
                l.append(temp)
        return l

    def colliderect(self, rect, topleft=(0,0)):
        """self.colliderect(rect, [tuple]) -> list
        Calls the colliderect method for all sprites in group.
        Returns a list of all sprites that return True."""
        l = []
        for temp in self:
            if temp.colliderect(rect, topleft):
                l.append(temp)
        return l

    def collidegroup(self, group, topleft=(0,0)):
        """self.collidegroup(Group, [tuple]) -> list
        Checks for collisions between the two groups.
        Returns a list of results in self that evaluate as True."""
        l = []
        for temp1 in self:
            for temp2 in group:
                if temp1.colliderect(temp2.rect, topleft):
                    l.append(temp1)
                    break
        return l

    def lock(self):
        """self.lock() -> None
        Calls the lock method for all sprites in group."""
        for temp in self:
            temp.lock()

    def unlock(self):
        """self.unlock() -> None
        Calls the unlock method for all sprites in group."""
        for temp in self:
            temp.unlock()

    def templock(self):
        """self.templock() -> None
        Calls the templock method for all sprites in group."""
        for temp in self:
            temp.templock()

    def set_seq(self, seq_name, repititions=1):
        """self.set_seq(str, [int]) -> None
        Calls the set_seq method for all sprites in group."""
        for temp in self:
            temp.set_seq(seq_name, repititions)
    
sprite.Group = TempClass #Group class will be accessed through sprite.Group
TempClass.__name__ = 'sprite.Group'
del TempClass #Remove TempClass reference

sprite.GroupSingleBase = sprite.GroupSingle #sprite.GroupSingleBase refers to original sprite.GroupSingle
class TempClass(sprite.GroupSingleBase):
    """This class will serve as a more useful groupsingle class."""
    def draw(self, surf, topleft=(0,0)):
        """self.draw(surface, [tuple]) -> None
        Calls the draw method for sprite in group."""
        self.sprite.draw(surf, topleft)

    def clear(self, surf, background, topleft=(0,0)):
        """self.clear(surface, surface, [tuple]) -> None
        Calls the clear method for sprite in group."""
        self.sprite.clear(surf, background, topleft)

    def fill(self, surf, color, topleft=(0,0)):
        """self.fill(surface, tuple, [tuple]) -> None
        Calls the fill method for sprite in group."""
        self.sprite.fill(surf, color, topleft)

    def collidepoint(self, point, topleft=(0,0)):
        """self.collidepoint(tuple, [tuple]) -> Bool
        Calls the collidepoint method for sprite in group.
        Returns the result."""
        return self.sprite.collidepoint(point, topleft)

    def colliderect(self, rect, topleft=(0,0)):
        """self.colliderect(rect, [tuple]) -> Bool
        Calls the colliderect method for sprite in group.
        Returns the result."""
        return self.sprite.colliderect(rect, topleft)

    def collidegroup(self, group, topleft=(0,0)):
        """self.collidegroup(Group, [tuple]) -> Bool
        Returns True is sprite collides with any sprite in group."""
        for temp in group:
            if self.sprite.colliderect(temp.rect, topleft):
                return True
        return False

    def lock(self):
        """self.lock() -> None
        Call the lock method for sprite in group."""
        self.sprite.lock()

    def unlock(self):
        """self.unlock() -> None
        Call the unlock method for sprite in group."""
        self.sprite.unlock()

    def templock(self):
        """self.templock() -> None
        Call the templock method for sprite in group."""
        self.sprite.templock()

    def set_seq(self, seq_name, repititions=1):
        """self.set_seq(str, [int]) -> None
        Call the set_seq method for sprite in group."""
        self.sprite.set_seq(seq_name, repititions)

sprite.GroupSingle = TempClass #GroupSingle class will be accessed through sprite.GroupSingle
TempClass.__name__ = 'sprite.GroupSingle'
del TempClass #Remove TempClass reference
