#include <iostream>
#include <memory>
class ITruck {
public:
	virtual void Unloading() = 0;
};
class Train : public ITruck {
public:
	void Unloading() {
		std::cout << "Разгрузка краном\n";
	}
};
class Caravan : public ITruck {
public:
	void Unloading() {
		std::cout << "Авторазгрузка\n";
	}
};
class IStock {
public:
	virtual void PlacementWarehouse() = 0;
};
class Hangar :public IStock {
public:
	void PlacementWarehouse() {
		std::cout << "Размещение в ангаре\n";
	}
};
class Barge : public IStock {
public:
	void PlacementWarehouse() {
		std::cout << "Размещение на барже\n";
	}
};
class Accaunting {
public:
	Accaunting(std::shared_ptr<ITruck> truck, std::shared_ptr <IStock> stock) :_truck(truck), _stock(stock) {}
	void AccauntingCar() {
		_truck->Unloading();
		_stock->PlacementWarehouse();
	}
private:
	std::shared_ptr<ITruck> _truck;
	std::shared_ptr <IStock> _stock;
};

int main() {
	setlocale(LC_ALL, "Russian");
	std::string config;
	std::shared_ptr<ITruck> truck;
	std::cout << "Enter truck (train,caravan):";
	std::cin >> config;
	if (config == "train")
		truck = std::make_shared<Train>();
	else if (config == "caravan")
		truck = std::make_shared<Caravan>();
	std::shared_ptr<IStock> stock;
	std::cout << "Enter Stock (hangar,barge):";
	std::cin >> config;
	if (config == "hangar")
		stock = std::make_shared<Hangar>();
	else if (config == "barge")
		stock = std::make_shared<Barge>();
	
	Accaunting acc(truck, stock);
	acc.AccauntingCar();
	return 0;
}