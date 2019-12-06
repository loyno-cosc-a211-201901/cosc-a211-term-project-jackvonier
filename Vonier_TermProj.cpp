/* Jack's music player
    A music player that plays one of 5 tracks in a selected genre
    James vonier
    12/2/19*/



//THINGS I STILL WANT TO DO
    //Load file names and project them on the screen. It would take a little bit of reworking, but I could get it.  










#include <iostream>
#include <fstream>
using namespace std;

////////////////////
//Global Variables//
////////////////////

bool cancel = false;                    //Cancel the current genre
bool quit = false;                      //Quit program
string test = "Test failed!";           //THIS IS CALLED TEST BC IT TESTS WHETHER OR NOT THE FILE OPENED
//Genre Directories
const string CHILL_FOLDER_PATH = "C:\\Users\\banda\\Documents\\GitHub\\cosc-a211-term-project-jackvonier\\music\\chill";
const string ROCK_FOLDER_PATH = "C:\\Users\\banda\\Documents\\GitHub\\cosc-a211-term-project-jackvonier\\music\\rock";
//Song file names
const string FIRST_SONG_FILE = "song1.txt";
const string SECOND_SONG_FILE = "song2.txt";
const string THIRD_SONG_FILE = "song3.txt";
const string FOURTH_SONG_FILE = "song4.txt";
const string FIFTH_SONG_FILE = "song5.txt";



///////////////////////
//FUNCTION PROTOTYPES//
///////////////////////

int load_song (string file_dir);
int track_select(int selected_genre);
int open_genre(int selection);






/////////////////
//MAIN FUNCTION//
/////////////////

int main(){
    double genre;

    


    //Loop through the function
    while (!quit){
        //resetting cancel var
        cancel = false;

        //Prompts/main menu
        cout << "-----------------------------Welcome------------------------------" << endl;
        cout << "Welcome to Jack's Music Player! Please select your genre of music!" << endl;
        cout << "1. Chill\n2. Rock\n3. Quit Program\nInput: ";
        cin >> genre;

        //Check if Open Genre fails, if so end the program
        cout << "------------------------------------------------------------------" << endl;
        if (open_genre(genre) == 1){
            return 1;
        }
    }

    //Exit program
    cout << "Exiting program. ";
    return 0;
}






//////////////////////////
//Functions used in main//
//////////////////////////


//Declaring the function to open files
int load_song (string file_dir){
    ifstream fileHandle;
    fileHandle.open (file_dir);
    if (!fileHandle){
        cout << "Failed to open " + file_dir << endl;
        return 1;
    }

    //Assign test variable
    fileHandle >> test;

    fileHandle.close();
    return 0;
}


//Declaring the Track selection function
int track_select(int selected_genre){
    //Show new menu
    cout << "----------------------------TRACKLIST-----------------------------" << endl;

    //The input for the selected track
    int input;
    string song_file = "Error (line 96) song file not defined!\n";
    string file_dir = "Error (line 97) file directory not defined\n";

    //If the genre is Chill
    if (selected_genre == 1){
        //Setting file directory
        file_dir = CHILL_FOLDER_PATH;
        
        //Prompts
        cout << "TRACKLIST:" << endl;
        cout << "1. First Chill Song" << endl;
        cout << "2. Second Chill Song" << endl;
        cout << "3. Third Chill Song" << endl;
        cout << "4. Fourth Chill Song" << endl;
        cout << "5. Fifth Chill Song" << endl;
        cout << "6. Cancel" << endl;

        //Get the input
        cout << "Input: ";
        cin >> input;

        //testing the input
        switch (input){
            case 1:
                cout << "Selected chill 1 \n";
                song_file = FIRST_SONG_FILE;
                break;
            case 2:
                cout << "Selected chill 2 \n";
                song_file = SECOND_SONG_FILE;
                break;
            case 3:
                cout << "Selected chill 3 \n";
                song_file = THIRD_SONG_FILE;
                break;
            case 4:
                cout << "Selected chill 4 \n";
                song_file = FOURTH_SONG_FILE;
                break;
            case 5:
                cout << "Selected chill 5 \n";
                song_file = FIFTH_SONG_FILE;
                break;
            case 6:
                cout << "\nCancelled. Returning to main menu" << endl;
                cancel = true;
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
                return 0;
                break;
            default:
                cout << "Invaild Track number!\n";
                return 1;
        }


    //If the genre is rock
    }else if (selected_genre == 2){
        //Setting file directory
        file_dir = ROCK_FOLDER_PATH;

        //Prompts
        cout << "TRACKLIST:" << endl;
        cout << "1. First Rock Song" << endl;
        cout << "2. Second Rock Song" << endl;
        cout << "3. Third Rock Song" << endl;
        cout << "4. Fourth Rock Song" << endl;
        cout << "5. Fifth Rock Song" << endl;
        cout << "6. Cancel" << endl;

        //Get the input
        cout << "Input: ";
        cin >> input;

        //testing the input
        switch (input){
            case 1:
                cout << "Selected rock 1 \n";
                song_file = FIRST_SONG_FILE;
                break;
            case 2:
                cout << "Selected rock 2 \n";
                song_file = SECOND_SONG_FILE;
                break;
            case 3:
                cout << "Selected rock 3 \n";
                song_file = THIRD_SONG_FILE;
                break;
            case 4:
                cout << "Selected rock 4 \n";
                song_file = FOURTH_SONG_FILE;
                break;
            case 5:
                cout << "Selected rock 5 \n";
                song_file = FIFTH_SONG_FILE;
                break;
            case 6:
                cout << "\nCancelled. Returning to main menu" << endl;
                cancel = true;
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
                return 0;
                break;
            default:
                cout << "Invaild Track number!\n";
                return 1;
        }
    }

    

    //Load songs
    if (!cancel){       //Don't bother trying to load if cancelling
    
    //Show Loading
    cout << "------------------------------------------------------------------" << endl;
    cout << "----------------------------Loading-------------------------------" << endl;

    cout << "Loading songs from " << file_dir + "\\" + song_file << endl;

    //Combine directory and file name and test if loads
    if (load_song(file_dir + "\\" + song_file) == 0){
            cout << "Loaded song successfully\n" << endl;
            return 0;
        }else{
            //If song fail to load, end the program
            cout << "Failed to load song\n" << endl;
            return 1;
        }
    }
    
    return 0;

}




//Declaring the genre selection function
int open_genre(int selection){

    //check the selection variable for the genre selection and confirms it
    switch (selection){

        case 1:

            //Call and then check if track select failed. if so, end the program
            if (track_select(selection) == 1){
                return 1;
            }

            if (!cancel){   //Don't bother playing the song if cancelling
                //Actually play the song
                cout << "The song playing is: " << test << endl;            //I have the file dir and I can read from the file
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
            }
            break;
        case 2:

            //Check if track select failed if so, end the program
            if (track_select(selection) == 1){
                return 1;
            }
            if (!cancel){   //Don't bother playing the song if cancelling
                //Actually play the song
                cout << "The song playing is: " << test << endl;            //I have the file dir and I can read from the file
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
            }
            break;
        case 3:
            //Set quit variable to true
            cout << "Quitting program, see you again soon!\n" << endl;
            quit = true;
            break;
        default:
            cout << "Not a valid genre!\n";
            return 1;
    }

        return 0;
}