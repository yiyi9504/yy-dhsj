#include<bits/stdc++.h>
using namespace std;

class CashStrategy{
public:
    CashStrategy(){}
    virtual double AcceptCash(double x) = 0;
};

class CashNormal : public CashStrategy{
public:
    using CashStrategy::CashStrategy;
    double AcceptCash(double x){
        return x;
    }
};
class CashReturn: public CashStrategy{
private:
    double _condition;
    double _return;
public:
    using CashStrategy::CashStrategy;
    CashReturn(double condition, double ret):_condition(condition),_return(ret){}
    double AcceptCash(double x){
        return x-(int(x/_condition))*_return;
    }
};
class CashRebate : public CashStrategy{
private:
    double _rebate;    
public:
    using CashStrategy::CashStrategy;
    CashRebate(double rebata):_rebate(rebata){}
    double AcceptCash(double x){
        return x*_rebate;
    }
};

class CashContext{
private:
    CashStrategy* _cashStrategy;
    map<string, int> _strategyType = {
		{ "正常收费", 0 },
		{ "满300减100", 1 },
		{ "打8折", 2 }
    };    
public:
    CashContext(string type){
        int strategyTypeToint = _strategyType.at(type);
        switch (strategyTypeToint)
        {
            case 0:
                _cashStrategy = new CashNormal();
                break;
            case 1:
                _cashStrategy = new CashReturn(300,100);
                break;
            case 2:
                _cashStrategy = new CashRebate(0.8);
                break;                    
            default:
                break;
        }
    }
    double GetResult(double money){
        return _cashStrategy->AcceptCash(money);
    }
};

int main(){
    double x,n,ans=0; //单价x,n件
    int type;
    map<int, string> strategyType = {
		{ 0, "正常收费" },
		{ 1, "满300减100" },
		{ 2, "打8折" }
    }; 
    while(cin>>x){
        if(x==-1){ //输入-1清零
            cout << ans <<endl;
            ans=0;
        }else{
            cin >> n >> type;
            CashContext* context = new CashContext(strategyType.at(type));
            ans += context->GetResult(x*n);
            cout << ans <<endl;
        }
    }
    return 0;
}