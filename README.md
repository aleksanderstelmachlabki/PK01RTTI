1. W klasie Farm znajduje si� pole _animals. Napisz metody countCows() i countDogs() odpowiednio zwracaj�ce liczb� kr�w, oraz liczb� ps�w nale��cych do vectora _animals.

2. Napisz metod� klasy Farm i nazwij j� makeSomeNoiseVeryInelegant(Animal* animal, AnimalSpecies species). Metoda w zale�no�ci od argument�w wywo�uje:

	- bark() dla psa
	- moo() dla krowy
	- sayHello() dla innych zwierz�t

Metoda powinna pobiera� wska�nik na zwierz�, oraz gatunek w postaci enum class (w zale�no�ci od podanego gatunku metoda ma wywo�a� odpowiedni� funkcj�). 
Jakie s� wady tej implementacji? Sprawd� zachowanie metody podaj�c wska�nik na krow�, ale specyfikuj�c gatunek zwierz�tka jako pies. 
Napisz metod� makeSomeNoise(Animal* animal), nale��c� do klasy Farm, kt�ra b�dzie zachowywa� si� analogicznie do wy�ej wspomnianej metody, ale b�dzie wykorzystywa� mechanizm RTTI.

3. Napisz klas� CustomCastService. Klasa powinna zawiera� tylko statyczn� metod� custom_dynamic_cast<DestinationType*>(SourceType* source), 
kt�ra potrafi zrzutowa� typ bazowy Animal, na typ pochodny (Dog, Cow). W przypadku niepowodzenia metoda ma zwr�ci� nullptr. 
W tym celu wykorzystaj operator typeid. Napisz klas� Labrador dziedzicz�c� po klasie Dog i sprawd� zachowanie custom_dynamic_cast. 

4. Napisz metody transformAnimalsToDogsWithDynamicCast(std::vector<Animal*>& animals) i transformAnimalsToDogsWithCustomCast(std::vector<Animal*>& animals). 
Metody maj� rzutowa� vector Animals�w na vector Dogs, korzystaj�c odpowiednio z dynamic_cast, oraz wcze�niej napisanego custom_dynamic_cast. 
Nast�pnie napisz metod� testAnimalCastTime, w kt�rej stworzysz vector zawieraj�cy 100000000 wska�nik�w Animal* wskazuj�cych na psa. 
Metoda powinna kolejna wywo�a� transformAnimalsToDogsWithDynamicCast i transformAnimalsToDogsWithCustomCast. 
Zmierz czas wykonywania obu metod, oraz por�wnaj czasy (skompiluj aplikacj� w trybie Release, bez debuggera).

5. Stw�rzmy wska�nik typu Animal i zainicjujmy go jako nullptr. Jak zachowa si� nasza funkcja custom_dynamic_cast gdy podamy utworzony wska�nik jako argument?
Zabezpiecz dzia�anie funkcji przechwytuj�c odpowiedni wyj�tek w definicji custom_dynamic_cast. Je�li wyj�tek zostanie wy�apany, wyprowad� informacje o wyj�tku na ekran konsoli, oraz zwr�� nullptr.
