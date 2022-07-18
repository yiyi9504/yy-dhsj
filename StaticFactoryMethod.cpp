#include<bits/stdc++.h>
using namespace std;

class Operation{
public:
    Operation(){}
    Operation(double numA, double numB):NumberA(numA),NumberB(numB){}
    ~Operation(){}

    double NumberA;
    double NumberB;

    virtual double GetResult()=0;
};

class OperationAdd: public Operation{
    using Operation::Operation;
    double GetResult(){
        return NumberA + NumberB;
    }
};
class OperationSub: public Operation{
    using Operation::Operation;
    double GetResult(){
        return NumberA - NumberB;
    }
};
class OperationMul: public Operation{
    using Operation::Operation;
    double GetResult(){
        return NumberA * NumberB;
    }
};
class OperationDiv: public Operation{
    using Operation::Operation;
    double GetResult(){
        if(NumberB==0){
            throw "Divisor cannot be zero.";
        }
        return NumberA / NumberB;
    }
};

class OperationFactory{
private:
    map<string, int> _operationParam = {
		{ "+", 0 },
		{ "-", 1 },
		{ "*", 2 },
		{ "/", 3 }
    };
public:
    OperationFactory(){}
    Operation* createOperate(string operation){
        try{
            int operationToint = _operationParam.at(operation);
            switch (operationToint)
            {
                case 0:
                    return new OperationAdd();
                case 1:
                    return new OperationSub();
                case 2:
                    return new OperationMul();
                case 3:
                    return new OperationDiv();                
                default:
                    throw "Unexplained error";
            }            
        }catch(exception &e){
            throw e;
        }
    }
};

int main(){
    OperationFactory* operFactory = new OperationFactory();
    string operation;
    double numA,numB;
    while(cin>>operation){
        cin>>numA>>numB;
        try{
            Operation* oper= operFactory->createOperate(operation);
            oper->NumberA=numA;
            oper->NumberB=numB;
            cout << oper->GetResult()<<endl;          
        }catch(const char* msg){
            cout << msg << endl;
        }catch(exception &e){
            cout << e.what() << endl;
        }catch(...){
            cout << "Unexplained error" << endl;
        }
    }
    return 0;
}