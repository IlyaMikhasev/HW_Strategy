#include <iostream>
#include <memory>
class ITruck {
public:
	virtual void Unloading() = 0;
	~virtual ITruck(){}
};
class Train : public ITruck {
public:
	void Unloading() override{
		std::cout << "Ðàçãðóçêà êðàíîì";
	}
};
class Caravan : public ITruck {
public:
	void Unloading()override {
		std::cout << "Àâòîðàçãðóçêà";
	}
};
class IStock {
public:
	virtual void PlacementWarehouse() = 0;
	~virtual IStock(){}
};
class Hangar :public IStock {
public:
	Hangar(std::shared_ptr<ITruck> truck) :_truck(truck) {}
	Hangar() = delete;
	void PlacementWarehouse()override {
		_truck->Unloading();
		std::cout << " è ðàçìåùåíèå â àíãàðå\n";
	}
private:
	std::shared_ptr<ITruck> _truck;
};
class Barge : public IStock {
public:
	Barge(std::shared_ptr<ITruck> truck) :_truck(truck) {}
	Barge() = delete;
	void PlacementWarehouse()override {
		_truck->Unloading();
		std::cout << " è ðàçìåùåíèå íà áàðæå\n";
	}
private:
	std::shared_ptr<ITruck> _truck;
};
class Accaunting {
public:
	Accaunting( std::shared_ptr <IStock> stock) : _stock(stock) {}
	void AccauntingCar() {
		_stock->PlacementWarehouse();
	}
private:
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
		stock = std::make_shared<Hangar>(truck);
	else if (config == "barge")
		stock = std::make_shared<Barge>(truck);
	
	Accaunting acc(stock);
	acc.AccauntingCar();
	return 0;
}
