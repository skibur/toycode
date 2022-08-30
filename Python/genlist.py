# !/Python24/Python
# Application will get 4 input values:
# URL: The Beginning of the url to start transforming.
# Ext: The extensiuon of the file to transform.
# Zeros: How many 0s to add.
# Range: The range from where to begin and start 
#
# Usage: genlist [options]
# -u <url>          :Url needed to be added
# -x <extension>    :Extension that will be used without the . (dot)
# -z <zeros>        :Integer to determine number of placeholders.
# -r <num1> <num2>  :The range from where to start and where to begin
#


from sys import exit, argv
URLstr = EXTstr = ""
ZEROint = RANGEint1 = RANGEint2 = 0

########################################
##                                     #
##   Begin      Function Usage()       #
##                                     #
########################################

def printUsage():
    print """
    Usage: genlist.py [options]
        -u <url>          :Url needed to be added
        -x <extension>    :Extension that will be used without the . (dot)
        -z <zeros>        :Integer to determine number of placeholders.
        -r <num1> <num2>  :The range from where to start and where to begin
    """   

########################################
##                                     #
##   Begin   Function processArgs()    #
##                                     #
########################################

def processArgs(args):  # Process input arguments
    """Processed input Arguments provided by args."""
    global URLstr, EXTstr, ZEROint, RANGEint1, RANGEint2
    # get URL from list
    try:
        URLindex = args.index("-u")
        # print "Found URL index at: " + str(URLindex)
        URLstr = args[URLindex + 1]
        # print "Found URL: " + URLstr
    except ValueError: # if -u is not found in the list
        print "Error finding URL string."
        printUsage()
        exit()
    except IndexError: # if -u is the last in the list
        print "Index out of Range. (-u)"
        printUsage()
        exit()
    # print "First 4 Char: " + URLstr[0:4]
    if not (URLstr[0:4] == "http" or URLstr[0:4] == "ftp:"):
        exit("Invalid URL string.")

    # get extension from list
    try:
        EXTindex = args.index("-x")
        # print "Found Extension index at: " + str(EXTindex)
        EXTstr = args[EXTindex + 1]
        # print "Found Extension: " + EXTstr
    except ValueError: # if -x is not found...
        print "Error finding Extention."
        printUsage()
        exit()
    except IndexError: # if -x is the last in the list
        print "Index out of Range. (-x)"
        printUsage()
        exit()
        
    # get Zeroes from list
    try:
        ZEROindex = args.index("-z")
        # print "Found Zero index at: " + str(ZEROindex)
        ZEROstr = args[ZEROindex + 1]
        # print "Found Zeros: " + ZEROstr
    except ValueError: # if -z is not in list
        print "Error finding Zeros."
        printUsage()
        exit()
    except IndexError: # if -z is last in list
        print "Index out of Range. (-z)"
        printUsage()
        exit()
    try:
        ZEROint = int(ZEROstr)
    except ValueError: # if cannot convert to int
        print "Invalid integer number of Zeros."
        printUsage()
        exit()
    if ZEROint > 6:
        exit("Zero value larger than 6, please use a smaller value.")
    # print "Number of place holders: " + str(ZEROint)
    
    # get range of values...
    try:
        RANGEindex = args.index("-r")
        # print "Found Range index at: " + str(RANGEindex)
        RANGEstr1 = args[RANGEindex + 1]
        RANGEstr2 = args[RANGEindex + 2]
        # print "Found Range: " + RANGEstr1 + "-" + RANGEstr2
    except ValueError: # if -r is not in list
        print "Error finding range values."
        printUsage()
        exit()
    except IndexError: # if range limit 1 and 2 are not in list (-r is last)
        print "Index out of Range. (-r)"
        printUsage()
        exit()
    try:
        RANGEint1 = int(RANGEstr1)
        RANGEint2 = int(RANGEstr2) + 1 # allows range() to include last value
    except ValueError: # if cannot convert range limits to int
        print "Invalid Integers for range."
        printUsage()
        exit()
        
# End of processArgs function

########################################
##                                     #
##   Begin     Function main()         #
##                                     #
########################################

def main():
    """The main body of the program, loops and writes the
    output to a file."""
    global URLstr, EXTstr, ZEROint, RANGEint1, RANGEint2
    try:
        f=open("dlist",'w')
    except IOError:
        exit("Can't open 'dlist'.")
    for x in range(RANGEint1,RANGEint2):
        cmdtext = "wget " + URLstr + str(x).zfill(ZEROint) + "." + EXTstr + "\n"
        f.write(cmdtext)
        print cmdtext,
    f.close()
    print "file 'dlist' has been created."
# End of main function

########################################
##                                     #
##   Begin Program Start code Here     #
##                                     #
########################################

# print argv,
# print len(argv)
if len(argv) < 10:
    printUsage()
    exit()
else: processArgs(argv)

# TODO: Figure out how to have global vars and private ones.

print "URLstr    : " + URLstr
print "EXTstr    : " + EXTstr
print "ZEROint   : " + str(ZEROint)
print "RANGEint1 : " + str(RANGEint1)
print "RANGEint2 : " + str(RANGEint2)

main()
