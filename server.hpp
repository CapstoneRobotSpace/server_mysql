#include <iostream>
#include "mysql/mysql.h"
#include <string>

using namespace std;

class MySQLServer
{
	public:
		MySQLServer(string ip,string data_base);
		~MySQLServer();
		int sendCommand(string command);
		void showResponse();
	private:
		MYSQL *connection,mysql;
		MYSQL_RES* result;
		MYSQL_ROW row;
};

MySQLServer::MySQLServer(string ip,string data_base){
	cout<<"init mysql..."<<endl;
	mysql_init(&mysql);
	cout<<"complete init!!"<<endl;
	cout<<"connect to data base..."<<endl;
	connection = mysql_real_connect(&mysql,ip.c_str(),"root","1234",data_base.c_str(),0,NULL,0);
	cout<<"connection success!!"<<endl;
	if(connection == NULL)
		cout<<mysql_error(&mysql)<<endl;
}

MySQLServer::~MySQLServer(){
	cout<<"cose server..."<<endl;
	mysql_free_result(result);
	mysql_close(connection);
}

int MySQLServer::sendCommand(string command){
	int state;
	state = mysql_query(connection,command.c_str());
	if(state){
		cout<<mysql_error(connection)<<endl;
	}
	return state;
}

void MySQLServer::showResponse(){
	result = mysql_store_result(connection);
	int num_fields = mysql_num_fields(result);
	cout<<endl<<"============result============"<<endl;
	while(row = mysql_fetch_row(result)){
		for(int i=0;i<num_fields;i++)
			cout<<row[i]<<" ";
		cout<<endl;
	}
	cout<<"==============================="<<endl<<endl;
}
