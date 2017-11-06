#include<iostream>
using namespace std;
class modeoftransportation;
class transportstrategy{
	
	modeoftransportation* st=NULL;
	enum format{bus=0,car,train};
	
	public: 
		   void setstrategy(int type);
		   void doit();
		   
		
};


class modeoftransportation{
  	public: 
			virtual void feel()=0;
			virtual void security_measure()=0;
			virtual void costandtime()=0; 
			void doit(){
				feel();
				security_measure();
				costandtime();
			}
};

class carstrategy:public modeoftransportation{
	public:
		    void feel(){
				cout<<"awsm\n";
			}
			
			void security_measure(){
				cout<<"ensure your seat bealt\n";
			}
			void costandtime(){
				cout<<"expensive and fast\n";
			}
			
};

class busstrategy:public modeoftransportation{
	public:
		    void feel(){
				cout<<"do not feel good..\n";
			}
			
			void security_measure(){
				cout<<"do not put your hands outside the bus \n";
			}
			void costandtime(){
				cout<<"cheap and slow\n";
			}
};

class trainstrategy:public modeoftransportation{
	public:
		    void feel(){
				cout<<"average feeling\n";
			}
			
			void security_measure(){
				cout<<"do not stand in the middle of the boggies\n";
			}
			void costandtime(){
				cout<<"very cheap and fast\n";
			}
};

void transportstrategy::setstrategy(int type){
			    delete st;
				if(type==bus){
					st=new busstrategy;
				}else if(type==car){
					st=new carstrategy;
				}else if(type==train){
					st=new trainstrategy;
				}
}

void transportstrategy::doit(){
    
    st->doit();
}

int main(){
	
	transportstrategy c;
	for(int i=0;i<3;i++){
		c.setstrategy(i);
		c.doit();
	}
}