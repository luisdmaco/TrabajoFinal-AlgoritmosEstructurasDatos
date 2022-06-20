#pragma once
class Convertir {
private:

public:
	Convertir() {}
	~Convertir() {}

	long long convertir(long long monto) {
		monto = monto * 3.75;
		return monto;
	}
};