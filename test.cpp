#include "server.hpp"
int main(int argc,char** argv){
	MySQLServer life_server("222.121.110.229","marker");
	string command;
	while(1){
		command = "replace into info values(1,37.3486,126.678,2021-04,0)";
		if(!life_server.sendCommand(command)){
			if(command.substr(0,7) != "replace"){
				life_server.showResponse();	
			}
		}
	}
	
	return 0;
}