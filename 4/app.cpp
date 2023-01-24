#include "app.hpp"
App::App() {
    table = Table<Hash, Deposit>();
}
void App::show_help() const{
    std::cout <<"Short guide:\n" 
         << "1. Create new deposit\n"
         << "2. Work with deposit\n"
         << "3. Show all deposits\n"
         << "4. Exit\n";
}
void App::start(){
    std::cout << "Welcome to brand new bank account app\n";
    show_help();
    int c = 0;
    while(c != EXIT)
    {
        c = main_menu();
        if(c == 1 ){
            std::cout << "Invalid choice\n";
        }
    }
}

int get_choice()
{
    int ret;
    std::cout << "> ";
    std::cin >> ret;
    return ret;
}

int App::main_menu(){
    std::srand(std::time(NULL));
    std::string header = "| Num |  Type   |  Opened  |  LastOp  |Cur|Diff|       Value      |  % |";
    int choice = get_choice();
    switch(choice)
    {
        case 1:
            try{
            insert();
            }catch(int e)
            {
                std::cout << "ERROR INSERT!\n";
            }
            return OK;
            break;
        case 2:
            try{
            manage_deposit();
            }catch(int e)
            {
                std::cout << "ERROR MANAGE!\n";
            }
            return OK;
            break;
        case 3:
            table.Show(header);
            return OK;
            break;
        case 4:
            return EXIT;
            break;
    }
    return ERROR;
}
void App::insert(){
    int deposit_type;
    std::cout << "Choose deposit type:\n" 
         << "1. Casual   deposit\n" 
         << "2. Fast     deposit\n"
         << "3. Currency deposit\n";
    deposit_type = get_choice();
    switch(deposit_type)
    {
        case 1:
            insert_casual();
            break;
        case 2:
            insert_fast();
            break;
        case 3:
            insert_currency();
            break;
        default:
            throw ERROR;  
    }   
}
void App::insert_casual()
{
    Hash code;
    int done = 0;
    while(!done)
    {
        code = std::rand();
        try{
            table[code];
        }catch(int e)
        {
            done = 1;
        }
    }
    double value, percent;
    unsigned d, m,y;
    std::cout << "Enter value of deposit: ";
    std::cin >> value;
    std::cout << "Enter percent of deposit: ";
    std::cin >> percent;
    std::cout << "Enter date when deposit was opened (DD MM YY): ";
    std::cin >> d >> m >> y;
    Deposit n(code, value, percent, Date(d,m,y));
    table.Insert(std::make_shared<Deposit>(n));
}

void App::insert_fast()
{
    Hash code;
    int done = 0;
    while(!done)
    {
        code = std::rand();
        try{
            table[code];
        }catch(int e)
        {
            done = 1;
        }
    }
    double value, percent;
    unsigned d, m,y,d1,m1,y1;
    std::cout << "Enter value of deposit: ";
    std::cin >> value;
    std::cout << "Enter percent of deposit: ";
    std::cin >> percent;
    std::cout << "Enter date when deposit was opened (DD MM YY): ";
    std::cin >> d >> m >> y;
    std::cout << "Enter deposit close date (DD MM YY): ";
    std::cin >> d1 >> m1 >> y1;
    FastDeposit n(code, value, percent, Date(d,m,y), Date(d1,m1,y1));
    table.Insert(std::make_shared<Deposit>(n));
}
void App::insert_currency()
{
    Hash code;
    int done = 0;
    while(!done)
    {
        code = std::rand();
        try{
            table[code];
        }catch(int e)
        {
            done = 1;
        }
    };
    double value, percent, diff;
    unsigned d, m,y;
    std::string name;
    std::cout << "Enter value of deposit: ";
    std::cin >> value;
    std::cout << "Enter percent of deposit: ";
    std::cin >> percent;
    std::cout << "Enter curenncy of deposit (for example USD): ";
    std::cin >> name ;
    std::cout << "Enter difference beetwen this curenncy and RUB(for example if you input 2 means that RUB 2 times smaller): ";
    std::cin >> diff ;
    std::cout << "Enter date when deposit was opened (DD MM YY): ";
    std::cin >> d >> m >> y;
    CurrencyDeposit n(code,name ,value, percent,diff ,Date(d,m,y));
    table.Insert(std::make_shared<Deposit>(n));
}

void App::manage_deposit()
{
    Hash key;
    std::shared_ptr<Deposit> ret;
    bool shit = false;
    std::cout << "Enter deposit number: ";
    std::cin >> key;
    try{
        ret = table[key];
    }catch (int e)
    {
        std::cout << "Error! No such element\n";
        shit = true;
    }
    if(!shit)
    {
        ret->Show();
        std::cout << "Choose option:\n"
                  << "1. Modify  deposit\n"
                  << "2. Close deposit\n"
                  << "3. Go back\n";
        int choice = get_choice();
        switch(choice)
        {
            case 1:
                modify_deposit(ret);
                break;
            case 2:
                close_deposit(ret);
                break;
        }
    }
}

void App::modify_deposit( std::shared_ptr<Deposit> d)
{
    std::cout << "Choose option:\n"
              << "1. Insert some money\n"
              << "2. Take percents\n"
              << "3. Take money\n";
    int choice = get_choice();
    switch(choice)
    {
        case 1:
            try{
            insert_money(d);
            }catch(int e)
            {
                std::cout << "You can not insert negative money!\n";
            }
            break;
        case 2:
            take_perc(d);
            break;
        case 3:
            try {
                take_money(d);
            }catch(int e) {
                std::cout << "You can not take negative money!\n";
            }
            
            break;
    }
}

void App::insert_money(std::shared_ptr<Deposit> deposit)
{
    unsigned d, m, y;
    std::cout << "Enter date: ";
    std::cin >> d >> m >> y;
    double money;
    std::cout << "Enter amount: ";
    std::cin >> money;
    if (money < 0)
    {
        throw ERROR;
    }
    deposit->AddValue(deposit->CountPercents(Date(d,m,y)));
    deposit->AddValue(money);
    std::cout << "Added successfully\n";
}
void App::take_perc(std::shared_ptr<Deposit> deposit){
    unsigned d, m, y;
    std::cout << "Enter date: ";
    std::cin >> d >> m >> y;
    double percents = deposit->CountPercents(Date(d,m,y));
    std::cout << "You've taken " << percents << '\n';
}

void App::take_money(std::shared_ptr<Deposit> deposit)
{
    unsigned d, m, y;
    std::cout << "Enter date: ";
    std::cin >> d >> m >> y;
    double money;
    std::cout << "Enter amount: ";
    std::cin >> money;
    money = -money;
    if (money > 0)
    {
        throw ERROR;
    }
    deposit->AddValue(deposit->CountPercents(Date(d,m,y)));
    deposit->AddValue(money);
    std::cout << "Took successfully\n";
}
void App::close_deposit( std::shared_ptr<Deposit> deposit)
{
    unsigned d, m, y;
    std::cout << "Enter date: ";
    std::cin >> d >> m >> y;
    double cash = deposit->GetValue() + deposit->CountPercents(Date(d,m,y));
    table.DeleteElement(deposit->GetCode());
    std::cout << "You took: " << cash << '\n';
}