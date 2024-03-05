#include <iostream>
using namespace std;

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister() {
        cashOnHand = 1200;
    }

    cashRegister(int cashIn) {
        cashOnHand = cashIn;
    }

    int getCurrentBalance() const {
        return cashOnHand;
    }

    void acceptAmount(int amountIn) {
        cashOnHand += amountIn;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType() {
        numberOfItems = 40;
        cost = 75;
    }

    dispenserType(int setNoOfItems, int setCost) {
        numberOfItems = setNoOfItems;
        cost = setCost;
    }

    int getNoOfItems() const {
        return numberOfItems;
    }

    int getCost() const {
        return cost;
    }

    void makeSale() {
        numberOfItems--;
    }
};

void showSelection() {
    cout << "* МЕНЮ *\n";
    cout << "1. Конфеты\n";
    cout << "2. Чипсы\n";
    cout << "3. Жвачка\n";
    cout << "4. Печенье\n";
    cout << "Введите номер выбранного товара: ";
}

void sellProduct(dispenserType& productDispenser, cashRegister& cash) {
    int cost = productDispenser.getCost();
    int balance = cash.getCurrentBalance();
    int cashIn;

    if (productDispenser.getNoOfItems() > 0) {

        cout << "Стоимость товара: " << cost << "руб. ";

        cout << "Внесите сумму: ";
        cin >> cashIn;
        if (cashIn >= cost) {
            if (balance >= cashIn - cost) {
                productDispenser.makeSale();
                cash.acceptAmount(cost);
                cout << "Ваш товар!\n";
                cout << "Ваша сдача: " << cashIn - cost << "руб.\n";
            }
            else {
                cout << "В автомате нет сдачи :(\nВнесите меньшую сумму.\n";
            }
        }
        else {
            cout << "Недостаточно средств. Внесите большую сумму.\n";
        }
    }
    else {
        cout << "Товара нет в наличии:(\n";
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cashRegister cash(1500);
    dispenserType sweets(35, 60), chips(30, 85), bubbleGum(45, 50), bisquits(25, 70);

    int choice;
    showSelection();
    cin >> choice;

    switch (choice) {
    case 1:
        sellProduct(sweets, cash);
        break;
    case 2:
        sellProduct(chips, cash);
        break;
    case 3:
        sellProduct(bubbleGum, cash);
        break;
    case 4:
        sellProduct(bisquits, cash);
        break;
    default:
        cout << "Неправильный выбор.\n";
        break;
    }

    return 0;
}
