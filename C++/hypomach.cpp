//      Machine language interpreter for architecture of Runnion p. 19
#include <iomanip.h>
#include <stdlib.h>
typedef         long    WordSize;
typedef         int     AddressRange;
typedef         int     CodeSize;

using namespace std;

WordSize        Memory[ 1000 ], IR, A, B, MDR; // Machine architecture
AddressRange    PC, MAR;

int Interpret()      // Interpret program instructions stored in memory
{       WordSize        Temp;
        CodeSize        OP;
        AddressRange    Addr;
        cout << "PC  OP  Addr      A      B" << "\n";   A = 0;  B = 0;

        PC = 0;

        while (1)  {                           // Forever
            MAR = PC;
            MDR = Memory[MAR];
            IR  = MDR;                                  // Fetch

            cout << setw(2) << PC;

            PC = PC + 1;                               // Increment PC

            OP   = IR / 1000;                          // Decode
            Addr = IR % 1000;

            cout << setw(4) << OP << setw(6) << Addr << setw(7) << A
                 << setw(7) << B << "\n";

            switch (OP) {                   // Execute OP
                 case 01 : MAR = Addr;                  // LDA Addr
                           MDR = Memory[ MAR ];
                           A   = MDR;
                           break;
                 case 02 : MAR = Addr;                  // STA Addr
                           MDR = A;
                           Memory[ MAR ] = MDR;
                           break;
                 case 03 : {      Temp = A;             // XAB
                                  A    = B;
                                  B    = Temp;
                                  break;
                           }
                 case 04 : A = 0;                       // CLA
                           break;
                 case 20 : MAR = Addr;                  // ADD Addr
                           MDR = Memory[ MAR ];
                           A = A + MDR;
                           break;
                 case 21 : MAR = Addr;                  // SUB Addr
                           MDR = Memory[ MAR ];
                           A = A - MDR;
                           break;
                 case 30 : PC = Addr;                   // JMP
                           break;
                 case 99 : exit(0);                     // HLT
            }
      }
}
int Load()         // Load instructions into memory from file
{       char Line[80];
        PC = 0;
        cin >> dec >> IR;               cin.getline(Line, 80, '\n');
        while (cin) {
                Memory[ PC ] = IR;
                PC = PC + 1;
                cin >> dec >> IR;       cin.getline(Line, 80, '\n');
        }
}
int main()
{    Load();
     Interpret();
}
