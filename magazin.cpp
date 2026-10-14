#include <iostream>
#include <Windows.h>

const double applePrice = 100.99, orangePrice = 120.99, adricosPrice = 130.99, pearPrice = 140.99;
const double tomatPrice = 150.99, lykoviPrice = 280.99, cucumberPrice = 250.99;
const double garlicPrice = 350.99, parsleyPrice = 310.99;
const double boyarPrice = 499.99;

int litapple = 0, litorange = 0, litabricos = 0, litpear = 0, littomat = 0, litlykovi = 0, litcucumber = 0, litgarlic = 0, litparsley = 0, litboyar = 0;

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int choose = 1;

	while (true)
	{
		system("cls");
		std::cout << "---Соки Александра---\n";
		std::cout << "---Выбор раздела---\n";
		std::cout << "1) Фруктовый.\n";
		std::cout << "2) Овощной.\n";
		std::cout << "3) Чаи.\n";
		std::cout << "4) Боярышник.\n";
		std::cout << "5) Чек и выход.\n";
		std::cout << "0) Выход.\n";
		std::cout << "Ввод: ";
		std::cin >> choose;

		if (choose == 0)
		{
			break;
		}

		if (choose == 1)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n---Ассортимент Фруктового раздела---\n";
				std::cout << "\n1) Яблочный.(" << applePrice << "руб/л) (В корзине: " << litapple << "л)\n";
				std::cout << "\n2) Апельсиновый.(" << orangePrice << "руб/л) (В корзине: " << litorange << "л)\n";
				std::cout << "\n3) Абрикосовый.(" << adricosPrice << "руб/л) (В корзине: " << litabricos << "л)\n";
				std::cout << "\n4) Грушевый.(" << pearPrice << "руб/л) (В корзине: " << litpear << "л)\n";
				std::cout << "\n0) Назад.\n";
				std::cout << "Ввод: ";
				int liters, choosee;
				std::cin >> choosee;
				if (choosee == 0)
				{
					break;
				}
				else if (choosee >= 1 && choosee <= 4)
				{
					std::cout << "Введите количество желаемых литров: ";
					std::cin >> liters;
					if (liters > 0)
					{
						if (choosee == 1) litapple += liters;
						if (choosee == 2) litorange += liters;
						if (choosee == 3) litabricos += liters;
						if (choosee == 4) litpear += liters;

						// Условие: покупка фруктового аннулирует боярышник и блокирует его
						if (litboyar > 0)
						{
							litboyar = 0;
							std::cout << "\nВнимание! Куплен фруктовый сок, Боярышник аннулирован!\n";
							Sleep(1500);
						}
					}
				}
			}
		}
		else if (choose == 2)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n---Ассортимент Овощного раздела---\n";
				std::cout << "\n1) Томатный.(" << tomatPrice << "руб/л) (В корзине: " << littomat << "л)\n";
				std::cout << "\n2) Луковый.(" << lykoviPrice << "руб/л, каждый 4-й в подарок) (В корзине: " << litlykovi << "л)\n";
				std::cout << "\n3) Огуречный.(" << cucumberPrice << "руб/л) (В корзине: " << litcucumber << "л)\n";
				std::cout << "\n0) Назад.\n";
				std::cout << "Ввод: ";
				int chooose, litvin;
				std::cin >> chooose;

				if (chooose == 0)
				{
					break;
				}
				else if (chooose >= 1 && chooose <= 3)
				{
					std::cout << "Введите количество желаемых литров: ";
					std::cin >> litvin;
					if (litvin > 0)
					{
						if (chooose == 1) littomat += litvin;
						if (chooose == 2) litlykovi += litvin;
						if (chooose == 3) litcucumber += litvin;
					}
				}
			}
		}
		else if (choose == 3)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n---Ассортимент Чаев---\n";
				std::cout << "\n1) Чесночный чай.(" << garlicPrice << "руб/л) (В корзине: " << litgarlic << "л)\n";
				std::cout << "\n2) Петрушечный чай.(" << parsleyPrice << "руб/л, скидка 5% от 3л) (В корзине: " << litparsley << "л)\n";
				std::cout << "\n0) Назад.\n";
				std::cout << "Ввод: ";
				int choooseTea, litTea;
				std::cin >> choooseTea;

				if (choooseTea == 0)
				{
					break;
				}
				else if (choooseTea >= 1 && choooseTea <= 2)
				{
					std::cout << "Введите количество желаемых литров: ";
					std::cin >> litTea;
					if (litTea > 0)
					{
						if (choooseTea == 1) litgarlic += litTea;
						if (choooseTea == 2) litparsley += litTea;
					}
				}
			}
		}
		else if (choose == 4)
		{
			// Проверка на покупку фруктовых соков
			if (litapple > 0 || litorange > 0 || litabricos > 0 || litpear > 0)
			{
				system("cls");
				std::cout << "\nДоступ к покупке Боярышника заблокирован (в корзине есть фруктовый сок)!\n";
				std::cout << "Нажмите Enter для продолжения...";
				std::cin.ignore();
				std::cin.get();
				continue;
			}

			system("cls");
			std::cout << "\n---Боярышник---\n";
			std::cout << "\n1) Боярышник.(" << boyarPrice << "руб/л) (В корзине: " << litboyar << "л)\n";
			std::cout << "\n0) Назад.\n";
			std::cout << "Ввод: ";
			int chooseBoyar;
			std::cin >> chooseBoyar;

			if (chooseBoyar == 1)
			{
				std::cout << "Введите количество желаемых литров: ";
				int litersBoyar;
				std::cin >> litersBoyar;
				if (litersBoyar > 0)
				{
					litboyar += litersBoyar;
				}
			}
		}
		else if (choose == 5)
		{
			system("cls");
			std::cout << "\n--- ЧЕК ---\n";
			double total = 0;

			if (litapple > 0)
			{
				double c = litapple * applePrice;
				total += c;
				std::cout << "Яблочный: " << litapple << "л = " << c << " руб.\n";
			}
			if (litorange > 0)
			{
				double c = litorange * orangePrice;
				total += c;
				std::cout << "Апельсиновый: " << litorange << "л = " << c << " руб.\n";
			}
			if (litabricos > 0)
			{
				double c = litabricos * adricosPrice;
				total += c;
				std::cout << "Абрикосовый: " << litabricos << "л = " << c << " руб.\n";
			}
			if (litpear > 0)
			{
				double c = litpear * pearPrice;
				total += c;
				std::cout << "Грушевый: " << litpear << "л = " << c << " руб.\n";
			}
			if (littomat > 0)
			{
				double c = littomat * tomatPrice;
				total += c;
				std::cout << "Томатный: " << littomat << "л = " << c << " руб.\n";
			}

			if (litlykovi > 0) {
				int paid = litlykovi - (litlykovi / 4);
				double c = paid * lykoviPrice;
				total += c;
				std::cout << "Луковый: " << litlykovi << "л (оплачено " << paid << ") = " << c << " руб.\n";
			}

			if (litcucumber > 0) { double c = litcucumber * cucumberPrice; total += c; std::cout << "Огуречный: " << litcucumber << "л = " << c << " руб.\n"; }
			if (litgarlic > 0) { double c = litgarlic * garlicPrice; total += c; std::cout << "Чесночный чай: " << litgarlic << "л = " << c << " руб.\n"; }

			if (litparsley > 0) {
				double c = litparsley * parsleyPrice;
				if (litparsley >= 3) {
					c *= 0.95;
					std::cout << "Петрушечный чай: " << litparsley << "л (скидка 5%) = " << c << " руб.\n";
				}
				else {
					std::cout << "Петрушечный чай: " << litparsley << "л = " << c << " руб.\n";
				}
				total += c;
			}

			if (litboyar > 0) { double c = litboyar * boyarPrice; total += c; std::cout << "Боярышник: " << litboyar << "л = " << c << " руб.\n"; }

			std::cout << "---------------------------------\n";
			std::cout << "Сумма: " << total << " руб.\n";

			if (total > 3000) {
				double skidka = total * 0.13;
				total -= skidka;
				std::cout << "Скидка 13% на весь чек: -" << skidka << " руб.\n";
			}

			std::cout << "ИТОГО К ОПЛАТЕ: " << total << " руб.\n";
			std::cout << "\nНажмите Enter для выхода...";
			std::cin.ignore();
			std::cin.get();
			break;
		}
	}

	return 0;
}