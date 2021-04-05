#include "server.hpp"
int main(int argc,char** argv){
	MySQLServer life_server("lifebest.iptime.org","marker");
	string command;
	while(1){
		cout<<"type query : ";
		getline(cin,command);
		if(!life_server.sendCommand(command)){
			if(command.substr(0,7) != "replace"){
				life_server.showResponse();	
			}
		}
	}
	
	return 0;
}