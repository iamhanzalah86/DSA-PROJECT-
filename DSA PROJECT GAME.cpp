#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>

 using namespace std;

     // Global variables
     int skip = 0, ret, exp, no, quest, ex, hp, mon, att = 1, plstr = 8, ophp, opend, opstr, opatt, sinp,
            oppo = 0, monid,bleed=0,
            plend = 8, opstun = 0, stun, unspentskp = 8,damageMultiplier=0,po=0;
    string op;
    
    	queue <int> beh;
class behaviour {
	public:
	int thr() {
		//random 30% chance to cause 1.5 damage
        int multi=1;
		srand(time(0)); // Seed the random number generator
        int knifethrust = 1; // Default damage multiplier
        if (rand() % 100 < 30) { 
            multi = 1.5;   
        }

        knifethrust =(int)(1 + (opstr * multi * 1.15) - (plend * 0.1));
        return knifethrust;
	}
 int slash() {
        srand(time(0)); // Seed the random number generator
int dmg;
         damageMultiplier = 1; // Default damage multiplier
        if (rand() % 100 < 5) { // 5% chance
            damageMultiplier = 2; // Apply 2x damage
        }
        
        dmg = (int)(1 + (opstr * damageMultiplier * 1.0) - (plend * 0.1));
        damageMultiplier=1;
		return dmg;
    }
	int lacerate(){
		//70% chance to hit and 50% chance to bleed along with 20% more damage than slash
		int dmg;
		  srand(time(0));
		  if (rand() % 100 < 70){
		  if (rand() % 100 < 50){
		  	bleed=3;
		  	
		  }
		  dmg=static_cast<int>(slash()*1.2);
		  
		  }
		  
		  return dmg;
	}
	int bite(){
		int dmg= (int)(1 + (opstr * damageMultiplier * 1.2) - (plend * 0.1));
		
		return dmg;
	}
	int rush(){
		int dmg= (int)(1 + (opstr * damageMultiplier * 1.0) - (plend * 0.1));
		return dmg;
	}
	int swipe(){
		int dmg = (int)(4 + (opstr * damageMultiplier * 1.0) - (plend * 0.1));
		return dmg;
	}
	int kslash(){
		opstr=opstr*2;
			int dmg= (int)(1 + (opstr * damageMultiplier * 1.2) - (plend * 0.1));
		opstr=opstr/2;
		return dmg;
	//	return dmg;
	}
	int bash(){
		opstr=opstr+3;
			int dmg= (int)(1 + (opstr * damageMultiplier * 1.2) - (plend * 0.1));
		
		return dmg;
	}
	int kick(){
		
			int dmg= (int)(1 + (opstr * damageMultiplier * 1.2) - (plend * 0.05));
		
		return dmg;
	}

	int web(){
		opend=8;
			int dmg= (int)(1 + (opstr * damageMultiplier * 1.2) - (plend * 0.3));
		
		return dmg;
	}
	int skitter(){
		opstr=opstr+3;
			int dmg= (int)(1 + (opstr * damageMultiplier * 1.2) - (plend * 0.1));
		
		return dmg;
	}
	int sbite(){
			int dmg= (int)(1 + (opstr * damageMultiplier * 1.2) - (plend * 0.1));
			po=3;
		return dmg;
	
	}
		int passive(){
			int x;
		
	
				switch(monid){
					case 1:
			        	x=lacerate();
			         	beh.push(x);			
						beh.push(x);
						x=slash();
						beh.push(x);  
						x=slash();
						beh.push(x);
						x=thr();
						beh.push(x);
	                	x=lacerate();
				        beh.push(x);			
						beh.push(x);
						x=slash();
						beh.push(x);
						x=slash();
						beh.push(x);
						x=thr();
						beh.push(x);
						x=lacerate();
				        beh.push(x);			
						beh.push(x);
						x=slash();
						beh.push(x);
						x=slash();
						beh.push(x);
						x=thr();
						beh.push(x);
						
						break;
						case 2:
							x=bite();
							beh.push(x);
							x=slash();
							beh.push(x);
							x=rush();
							beh.push(x);
							x=slash();
							beh.push(x);
							x=bite();
							beh.push(x);
							x=slash();
							beh.push(x);
							x=bite();
							beh.push(x);
							x=slash();
							beh.push(x);
							x=rush();
							beh.push(x);
							x=bite();
							beh.push(x);
							x=slash();
							beh.push(x);
							x=rush();
							beh.push(x);
							x=bite();
							beh.push(x);
							x=slash();
							beh.push(x);
							x=rush();
							beh.push(x);
							x=bite();
							beh.push(x);
							x=slash();
							beh.push(x);
							x=rush();
							beh.push(x);
						break;
						case 3:
								x=kslash();
								beh.push(x);
							x=kick();
							beh.push(x);
							x=thr();
								beh.push(x);
								x=bash();
							beh.push(x);
									x=kick();
							beh.push(x);
							x=slash();
								beh.push(x);
									x=thr();
								beh.push(x);
									x=thr();
								beh.push(x);
									x=slash();
								beh.push(x);
									x=slash();
								beh.push(x);
									x=kslash();
								beh.push(x);
										x=kick();
							beh.push(x);
							
							x=thr();
								beh.push(x);
								x=bash();
							beh.push(x);
							x=slash();
								beh.push(x);
									x=thr();
								beh.push(x);
									x=thr();
								beh.push(x);
									x=slash();
								beh.push(x);
									x=slash();
								beh.push(x);
									x=kslash();
								beh.push(x);
							
							x=thr();
								beh.push(x);
								x=bash();
							beh.push(x);
							x=slash();
								beh.push(x);
									x=thr();
								beh.push(x);
									x=thr();
								beh.push(x);
									x=slash();
								beh.push(x);
									x=slash();
								beh.push(x);
						
						break;
						case 4:
							x=bite();
								beh.push(x);
							x=slash();
								beh.push(x);
							x=kick();
								beh.push(x);
									x=bite();
								beh.push(x);
							x=slash();
								beh.push(x);
							x=kick();
								beh.push(x);
									x=bite();
								beh.push(x);
							x=slash();
								beh.push(x);
							x=kick();
								beh.push(x);
									x=bite();
								beh.push(x);
							x=slash();
								beh.push(x);
							x=kick();
								beh.push(x);
									x=bite();
								beh.push(x);
							x=slash();
								beh.push(x);
							x=kick();
								beh.push(x);
							
						break;
						case 5:
							x=skitter();
									beh.push(x);
							x=sbite();
									beh.push(x);
							x=web();
									beh.push(x);
										x=skitter();
									beh.push(x);
								x=skitter();
									beh.push(x);
							x=web();
									beh.push(x);
										x=skitter();
									beh.push(x);
										x=skitter();
									beh.push(x);
							x=sbite();
									beh.push(x);
							x=web();
									beh.push(x);
										x=skitter();
									beh.push(x);
						
							x=web();
									beh.push(x);
										x=skitter();
									beh.push(x);
										x=skitter();
									beh.push(x);
										x=web();
									beh.push(x);
										x=skitter();
									beh.push(x);
										x=skitter();
									beh.push(x);
										x=web();
									beh.push(x);
										x=skitter();
									beh.push(x);
										x=skitter();
									beh.push(x);
						break;
						default:
							break;
				}
			}
	
};
    class skilltr  {
    protected:
           string s;
           int skid;
    public:
    int skill1() {
        skid = 1001;
        s = "Poison throw";
        att = plstr * 2 - (opend / 2);
        stun = 0;
        oppo = 4;
        cout<<("You used POISON ATTACK!")<<endl;
        return skid;
    }

    int skill2() {
        skid = 1002;
        att = plstr * 3 - (opend / 2);
        stun = 1;
        cout<<("You used SHIELD BASH!")<<endl;
        s = "Shield bash";
        return skid;
    }

    int skill3() {
        skid = 1003;
        att = plstr * 4 - (opend / 2);
        stun = 0;
        cout<<("You used DOUBLE SLASH!")<<endl;
        s = "Double Slash";
        return skid;
    }

    int skill4() {
        skid = 1004;
        att = plstr * 5 - (opend / 2);
        stun = 0;
        cout<<("You used BURST STRIKE!")<<endl;
        s = "Burst strike";
        return skid;
    }

    int skill5() {
        skid = 1005;
        att = plstr * 6 - (opend / 2);
        stun = 50;
        cout<<("You used HEAD BASH!")<<endl;
        s = "Head strike";
        return skid;
    }

    int skill6() {
        skid = 1006;
        att = 20;
        stun = 77;
        cout<<("You used SPIRIT GUN!")<<endl;
        s = "Spirit gun";
        return skid;
    }

    int skill7() {
        skid = 1007;
        att = 20;
        stun = 7;
        cout<<("You used LASER BURST!")<<endl;
        s = "Laser burst";
        return skid;
    }

    int skill8() {
        skid = 1008;
        att = 1;
        stun = 2;
        cout<<("You used DEATH STARE!")<<endl;
        s = "Death stare";
        return skid;
    }

    int skill9() {
        skid = 1009;
        att = 100;
        stun = 0;
        cout<<("You used ENDEVOUR!")<<endl;
        s = "Endevour";
        return skid;
    }

    int skill10() {
        skid = 1010;
        att = 40;
        stun = 6;
        cout<<("You used END GAME!")<<endl;
        s = "End game";
        return skid;
    }
};

    class Skcall {
    skilltr skl;
public:
    void skill1(int s) {
    	
        switch (s) {
            case 1001:

                skl.skill1();
                break;
            case 1002:

                skl.skill2();
                break;
            case 1003:

                skl.skill3();
                break;
            case 1004:
                skl.skill4();
                break;
            case 1006:
                skl.skill6();
                break;
            case 1007:

                skl.skill7();
                break;
            case 1008:

                skl.skill8();
                break;
            case 1009:

                skl.skill9();
                break;
            case 1010:

                skl.skill10();
                break;
            case 1005:

                skl.skill5();
                break;
        }

    }
};

class Skshot : public skilltr {
	skilltr skl;
	public:
    
    int skid1;
    int skid2;
    int skid3;
    int skid4;
    string s1, s2, s3, s4;
public:
    void skull1() {
        int a, b;
        do {
            cout<<(
                    "Select your skill\n\n 1.Shield bash\t\t2.Poison throw\n3.Double slash\t\t4.Burst strike\n5.Head strike\t\t6.Spirit gun\n7.Laser burst\t\t8.Death stare\n9.Endeavour\t\t10.End game")<<endl;
           cin>>a;
            if (a < 1 || a > 10) {
                cout<<("Invalid Input")<<endl;
            }
        } while (a < 1 || a > 10);
        do {
            cout<<"Choose Slot\n1. "<<s1;
            cout<<"\n2. "<<s2;
             cout<<"\n3. "<<s3;
              cout<<"\n4. "<<s4<<endl;
		    cin>>b;
            if (b < 1 || b > 4) {
                cout<<("Invalid Input")<<endl;
            }
        } while (b < 1 || b > 4);
        switch (b) {
            case 1:
                switch (a) {
                    case 1:
                        s1 = "Shield bash";
                        skid1 = skl.skill1();
                        break;
                    case 2:
                        s1 = "Poison throw";
                        skid1 = skl.skill2();
                        break;
                    case 3:
                        s1 = "Double slash";
                        skid1 = skl.skill3();
                        break;
                    case 4:
                        s1 = "Burst strike";
                        skid1 = skl.skill4();
                        break;
                    case 5:
                        s1 = "Spirit gun";
                        skid1 = skl.skill5();
                        break;
                    case 6:
                        s1 = "Laser burst";
                        skid1 = skl.skill6();
                        break;
                    case 7:
                        s1 = "Death stare";
                        skid1 = skl.skill7();
                        break;
                    case 8:
                        s1 = "Endevour";
                        skid1 = skl.skill8();
                        break;
                    case 9:
                        s1 = "End game";
                        skid1 = skl.skill9();
                        break;
                    case 10:
                        s1 = "Head strike";
                        skid1 = skl.skill10();
                        break;
                    default:
                        cout<<("Incorrect input. Try again")<<endl;
                }
                break;
            case 2:
                switch (a) {
                    case 1:
                        s2 = "Shield bash";
                        skid2 = skl.skill1();
                        break;
                    case 2:
                        s2 = "Poison throw";
                        skid2 = skl.skill2();
                        break;
                    case 3:
                        s2 = "Double slash";
                        skid2 = skl.skill3();
                        break;
                    case 4:
                        s2 = "Burst strike";
                        skid2 = skl.skill4();
                        break;
                    case 5:
                        s2 = "Spirit gun";
                        skid2 = skl.skill5();
                        break;
                    case 6:
                        s2 = "Laser burst";
                        skid2 = skl.skill6();
                        break;
                    case 7:
                        s2 = "Death stare";
                        skid2 = skl.skill7();
                        break;
                    case 8:
                        s2 = "Endevour";
                        skid2 = skl.skill8();
                        break;
                    case 9:
                        s2 = "End game";
                        skid2 = skl.skill9();
                        break;
                    case 10:
                        s2 = "Head strike";
                        skid2 = skl.skill10();
                        break;
                    default:
                        cout<<("Incorrect input. Try again")<<endl;
                }
                break;
            case 3:
                switch (a) {
                    case 1:
                        s3 = "Shield bash";
                        skid3 = skl.skill1();
                        break;
                    case 2:
                        s3 = "Poison throw";
                        skid3 = skl.skill2();
                        break;
                    case 3:
                        s3 = "Double slash";
                        skid3 = skl.skill3();
                        break;
                    case 4:
                        s3 = "Burst strike";
                        skid3 = skl.skill4();
                        break;
                    case 5:
                        s3 = "Spirit gun";
                        skid3 = skl.skill5();
                        break;
                    case 6:
                        s3 = "Laser burst";
                        skid3 = skl.skill6();
                        break;
                    case 7:
                        s3 = "Death stare";
                        skid3 = skl.skill7();
                        break;
                    case 8:
                        s3 = "Endevour";
                        skid3 = skl.skill8();
                        break;
                    case 9:
                        s3 = "End game";
                        skid3 = skl.skill9();
                        break;
                    case 10:
                        s3 = "Head strike";
                        skid3 = skl.skill10();
                        break;
                    default:
                        cout<<("Incorrect input. Try again")<<endl;

                }
                break;
            case 4:
                switch (a) {
                    case 1:
                        s4 = "Shield bash";
                        skid4 = skl.skill1();
                        break;
                    case 2:
                        s4 = "Poison throw";
                        skid4 = skl.skill2();
                        break;
                    case 3:
                        s4 = "Double slash";
                        skid4 = skl.skill3();
                        break;
                    case 4:
                        s4 = "Burst strike";
                        skid4 = skl.skill4();
                        break;
                    case 5:
                        s4 = "Spirit gun";
                        skid4 = skl.skill5();
                        break;
                    case 6:
                        s4 = "Laser burst";
                        skid4 = skl.skill6();
                        break;
                    case 7:
                        s4 = "Death stare";
                        skid4 = skl.skill7();
                        break;
                    case 8:
                        s4 = "Endevour";
                        skid4 = skl.skill8();
                        break;
                    case 9:
                        s4 = "End game";
                        skid4 = skl.skill9();
                        break;
                    case 10:
                        s4 = "Head strike";
                        skid4 = skl.skill10();
                        break;
                    default:
                        cout<<("Incorrect input. Try again")<<endl;
                }
                break;
            default:
                break;
        }
    }
};
//linked list implementation for animation.. mainscreen and sworddd animationnss
struct Node {
    string frame;
    Node* next;

    Node(string f) : frame(f), next(NULL) {} // Use NULL instead of nullptr
};

class Animation {
private:
    Node* head;

public:
    Animation() : head(NULL) {} // Initialize with NULL

    ~Animation() {
        // Clean up memory
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void addFrame(const string& frame) {
        Node* newNode = new Node(frame);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void play(int delayMs = 500) const {
        Node* current = head;
        while (current) {
            clearScreen();
            cout << current->frame << endl;
            Sleep(delayMs); // Delay in milliseconds
            current = current->next;
        }
    }

    static void clearScreen() {
        system("CLS"); 
    }
};

class Gam {
public:

//string swordd = "|\\ \n| \\ \n|  \\ \n \\  \\ \n  \\  \\ \n   \\  \\ \n    \\  \\ \n     \\  \\ \n      \\  \\ \n       \\  \\ \n        \\  \\ \n         \\  \\ \n          \\__\\ \n            \\\\ \n             \\\\ \n              \\\\ \n               \\\\ \n                \\\\ \n                 \\\\ \n";
//string sword="   /|   \n  / |   \n /  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |__|   \n   ||  \n   ||  \n   ||  \n   ||   \n   ||  \n   ||  \n  (__) ";
//string swordl="  ___________________________\n /                           |__________________|\n/____________________________|------------------|\n";

    void ma(Skshot sks, Skcall SKK,behaviour behave) {
        mainscreen();
        
        system("mode con cols=100 lines=30"); // Set console to 40x20 resolution
        cout<<"\n\n\n\n\n\n\n\n";
        HANDLE y = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(y, 4);
        cout<<"==================================================================================================\n";
        cout<<"== WELCOME TO THE CITY OF AAGON.\t\t\t\t\t\t\t\t=="<<endl;
        cout<<"== YOU ARE AN ASPIRING ADVENTURER HOPING TO GET THE MEDALATION OF LEO THE BRAVEST OF ALL HEROES.=="<<endl;
        cout<<"== Now DEFEAT THE BEASTS OF DARKNESS FOR YOUR OWN GREED.\t\t\t\t\t=="<<endl;
        cout<<"==================================================================================================\n";
        cin.get(); // wait for user input
        clearScreen();
        HANDLE T = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(T, 7);
        stun = 0;

        do {
            do {
                cout<<"WHAT WOULD YOU LIKE TO DO?"<<endl;
                cout<<"1. GO TO THE HEALER"<<endl;
                cout<<"2. TAKE A QUEST"<<endl;
                if (unspentskp >= 1) {
                    cout<<("3. CHECK CHARACTER SHEET")<<endl;
                }

                cout<<("4. EQUIP SKILLS")<<endl;
                if (quest > 0) {
                    cout<<("5. GO FOR QUEST")<<endl;
                }
                cin>>ex;

                if (ex == 3 && unspentskp >= 1) {
                    chrscr();
                } else if (ex == 3 && unspentskp <= 0) {
                    cout<<"STRENGTH = " << plstr << "\nENDURANCE = " << plend<<endl;
                } else if (ex == 2) {
                    while (no < 1 || no > 2) {
                        cout<<("CHOOSE YOUR QUEST\n 1. PATROL THE FOREST\n 2. CLEAR THE RUINS")<<endl;
                        cin>>no;
                        switch (no) {
                            case 1: {
                               srand(static_cast<unsigned>(time(NULL)));
                               mon = 1 + (rand() % 5);
                                if (mon >= 1 && mon <= 3) {
                                    gob();
                                } else {
                                    dire();
                                }
                                break;
                            }
                            case 2: {
                                srand(static_cast<unsigned>(time(NULL)));
                                ret = 1 + (rand() % 10);
                                if (ret >= 1 && ret <= 5) {
                                    skl();
                                    
                                } else if (ret >= 6 && ret <= 8) {
                                   spider();
                                   
                                } else if (ret == 9 || ret == 10) {
                                    sklngt();
                                }
                                break;
                            }
                            default:
                                cout<<("Invalid\n")<<endl;
                                break;
                        }
                        quest++;
                        break;
                    }
                } else if (ex == 1) {
                	  hp = 1 + (plstr * 2) + (plend * 4); 
                    po=0; 
                    HANDLE x = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(x, 2);
                    cout<<"YOU HAVE BEEN HEALED AND CURED\nYOUR HEALTH IS NOW: " << hp<<endl; 
                    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(t, 7);
                } else if (ex == 4) {
                    sks.skull1();
                }
            } while (ex == 1 || ex == 2 || ex == 3 || ex == 4);

            clearScreen();
	       behave.passive();
            // Main game loop
            while (quest > 0 && ophp > 0 && hp > 0) {
                srand(static_cast<unsigned>(time(NULL)));
                int random = 1 + (rand() % 2);
                cout<<op;
                
                cout<<"HEALTH = " << ophp << "\t\t\t\t PLAYER HEALTH = " << hp<<endl;
                
                cout<<("\nWHAT WOULD YOU LIKE TO DO?\n\nA FOR ATTACK S FOR SKILL")<<endl;
                char ch;
                cin>>ch;

                // Player's turn
                if (ch == 'a' || ch == 'A') {
                    att = (int) (plstr * (1.15) - (opend * (0.1)));
                    cin.get(); // wait for user input
                    if (skip != 1) {
                        anim();
                        HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(t, 7);
                    }
                } else if (ch == 's' || ch == 'S') {
                    // Player chooses a skill
                    do {
                        cout<<"CHOOSE THE SKILL\n1. " << sks.s1 << "\n2. " << sks.s2 << "\n3. " << sks.s3
                                << "\n4. " << sks.s4<<endl;
                        cin>>sinp;
                        clearScreen();
                        switch (sinp) {
                            case 1:
                                SKK.skill1(sks.skid1);
                                break;
                            case 2:
                                // Call skill2 function
                                SKK.skill1(sks.skid2);
                                break;
                            case 3:
                                // Call skill3 function
                                SKK.skill1(sks.skid3);
                                break;
                            case 4:
                                // Call skill4 function
                                SKK.skill1(sks.skid4);
                                break;
                            default:
                                cout<<("TRY AGAIN")<<endl;
                        }

                    } while (sinp > 4 || sinp < 0);
                }
                if (ophp <= 0) {
                std::cout << "\nCONGRATULATIONS! YOU HAVE DEFEATED THE " << op << "!\n";
                break;
                }
                clearScreen();
				  // Determine opponent's attack based on random number
                if (random == 1) {
					
                    opatt = beh.front();
                    beh.pop();
                }
                // Handle stun effect on player
                if (stun > 0) {
                    opatt = 0;
                    stun--;
                }

                // Handle opponent's debuff effect on player
                if (oppo > 0) {
                    att = att + 5;
                    oppo--;
                }

                // Handle stun effect on opponent
                if (opstun > 0) {
                    
                    opstun--;
                }
				
                // Update opponent's health based on player's attack
                ophp = ophp - att;
                cout<<"You HIT THE ENEMY FOR " << att << " DAMAGE\n\n"<<endl;
if(bleed>0){
	
	hp=hp-10;
	cout<<"You bled for 10 HP"<<endl;
	bleed--;
}
if(po>0){
	hp=hp-5;
	cout<<"POISON!"<<endl;
	po--;
	
}
// this tooo
             if (hp <= 0) {
                std::cout << "\nYOU WERE DEFEATED BY THE " << op << ". BETTER LUCK NEXT TIME!\n";
                break;
               }

                // Update player's health based on opponent's attack
                hp = hp - opatt;
                cout<<"THE OPPONENT HIT YOU FOR " << opatt <<" DAMAGE\n\n"<<endl;
                
            }
            //a added this for win or loss condition output
             if (hp <= 0) {
             	HANDLE r = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(r, 4);
            cout << "\nGAME OVER: The monster has won.\n";
            HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(t, 7);
            } else if (ophp <= 0) {
            	HANDLE e = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(e, 6);
            cout << "\nVICTORY: You have defeated the monster!\n";
            unspentskp += exp; // Reward skill points
            HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(t, 7);
        }
        
        
            while(beh.front()){
            	beh.pop();
			}
            skip=0;
            quest=0;
            unspentskp += exp;
            no=0;
            
           

        } while (ex != 6);

       
    }

    void anim() {
    	 Animation swordAnimation;
    	 //colors handling 
    	 HANDLE y = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(y, 4);
        swordAnimation.addFrame("   /|   \n  / |   \n /  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |  |  \n |__|   \n   ||  \n   ||  \n   ||  \n   ||   \n   ||  \n   ||  \n  (__) ");
    	 swordAnimation.addFrame("|\\ \n| \\ \n|  \\ \n \\  \\ \n  \\  \\ \n   \\  \\ \n    \\  \\ \n     \\  \\ \n      \\  \\ \n       \\  \\ \n        \\  \\ \n         \\  \\ \n          \\__\\ \n            \\\\ \n             \\\\ \n              \\\\ \n               \\\\ \n                \\\\ \n                 \\\\ \n");

    	 swordAnimation.addFrame("  ___________________________\n /                           |__________________|\n/____________________________|------------------|\n");
    	 swordAnimation.play(500); // delay off how much it will play per frame

        skip++; // skip animation for other than 1st attack 
    }

    void mainscreen() {
    	system("color 47");
       Animation mainScreenAnimation;
       mainScreenAnimation.addFrame("\n\n\n\n\n\n\n\n\n\t\t\t\t\t************************************\n""\t\t\t\t\t*                                  *\n""\t\t\t\t\t*          WELCOME TO THE          *\n""\t\t\t\t\t*               GAME!              *\n""\t\t\t\t\t*                                  *\n""\t\t\t\t\t************************************" );
       mainScreenAnimation.play(1000);
       clearScreen();
       system("color 07");
       //handle colors of text
        HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(t, 7);
    }

    void chrscr() {
       try {
        while (unspentskp >= 1) {
            cout << "1. ENDURANCE = " << plend << "\t\t\t2. STRENGTH = " << plstr << "\t\t\tUNSPENT SKILL POINTS = " << unspentskp << endl;
            cout << "WOULD YOU LIKE TO SPEND ANY?\n1. ENDURANCE\n2. STRENGTH" << endl;
            cin >> sinp;

            switch (sinp) {
                case 1:
                    unspentskp--;
                    plend++;
                    break;
                case 2:
                    unspentskp--;
                    plstr++;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;  // Added break to avoid falling through
            }
        }
    } catch (...) {
           cout << "An error occurred during skill point allocation." << endl; // Added a general error message
    }
           cout << "STRENGTH = " << plstr << "\nENDURANCE = " << plend << endl;
    };

    void clearScreen() {
        system("CLS");
    }

    void gob() {
        opstr = 8;
        opend = 9;
        ophp = 1 + (opstr * 2) + (opend * 4);
        op = "GOBLIN";
        exp = 1;
          monid=1;
    }

    void dire() {
        opstr = 17;
        opend = 14;
        ophp = 1 + (opstr * 2) + (opend * 4);
        op = "DIRE WOLF";
        exp = 2;
           monid=2;
    }

    void sklngt() {
        opstr = 15;
        opend = 20;
        ophp = 1 + (opstr * 2) + (opend * 4);
        op = "SKELETON KNIGHT";
        exp = 3;
      monid=3;
    }

    void skl() {
        opstr = 12;
        opend = 9;
        ophp = 1 + (opstr * 2) + (opend * 4);
        op = "SKELETON";
        exp = 1;
  monid=4;
    }

    void spider() {
        opstr = 25;
        opend = 4;
        ophp = 1 + (opstr * 2) + (opend * 4);
        op = "SPIDER";
        exp = 2;
     monid=5;
    }

};

int main() {
	Gam g;
    Skshot sks;
    Skcall SKK;
    behaviour be;
    g.ma(sks,SKK,be);
    return 0;
}
