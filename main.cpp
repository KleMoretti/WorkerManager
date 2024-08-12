#include <iostream>
#include <vector>
#include"WorkerClass.h"
#include"Functions.h"
#include"Context.h"


int main() {
    std::vector<std::unique_ptr<Person>> WInfo;
    ReadInfo(WInfo);
    int number;
    do {
        Context();
        std::cin>>number;
        switch (number) {
            case 1:Exit();
                break;
            case 2:AddInformation(WInfo);
                break;
            case 3:ShowInformation(WInfo);
                break;
            case 4:DeleteInformation(WInfo);
                break;
            case 5:ModifyInformation(WInfo);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:std::cout<<"Error,please try again!"<<std::endl;
            break;
        }
    }while(number!=1);

    return 0;
}
