1. W klasie Farm znajduje siê pole _animals. Napisz metody countCows() i countDogs() odpowiednio zwracaj¹ce liczbê krów, oraz liczbê psów nale¿¹cych do vectora _animals.

2. Napisz metodê klasy Farm i nazwij j¹ makeSomeNoiseVeryInelegant(Animal* animal, AnimalSpecies species). Metoda w zale¿noœci od argumentów wywo³uje:

	- bark() dla psa
	- moo() dla krowy
	- sayHello() dla innych zwierz¹t

Metoda powinna pobieraæ wskaŸnik na zwierzê, oraz gatunek w postaci enum class (w zale¿noœci od podanego gatunku metoda ma wywo³aæ odpowiedni¹ funkcjê). 
Jakie s¹ wady tej implementacji? SprawdŸ zachowanie metody podaj¹c wskaŸnik na krowê, ale specyfikuj¹c gatunek zwierz¹tka jako pies. 
Napisz metodê makeSomeNoise(Animal* animal), nale¿¹c¹ do klasy Farm, która bêdzie zachowywaæ siê analogicznie do wy¿ej wspomnianej metody, ale bêdzie wykorzystywaæ mechanizm RTTI.

3. Napisz klasê CustomCastService. Klasa powinna zawieraæ tylko statyczn¹ metodê custom_dynamic_cast<DestinationType*>(SourceType* source), 
która potrafi zrzutowaæ typ bazowy Animal, na typ pochodny (Dog, Cow). W przypadku niepowodzenia metoda ma zwróciæ nullptr. 
W tym celu wykorzystaj operator typeid. Napisz klasê Labrador dziedzicz¹c¹ po klasie Dog i sprawdŸ zachowanie custom_dynamic_cast. 

4. Napisz metody transformAnimalsToDogsWithDynamicCast(std::vector<Animal*>& animals) i transformAnimalsToDogsWithCustomCast(std::vector<Animal*>& animals). 
Metody maj¹ rzutowaæ vector Animalsów na vector Dogs, korzystaj¹c odpowiednio z dynamic_cast, oraz wczeœniej napisanego custom_dynamic_cast. 
Nastêpnie napisz metodê testAnimalCastTime, w której stworzysz vector zawieraj¹cy 100000000 wskaŸników Animal* wskazuj¹cych na psa. 
Metoda powinna kolejna wywo³aæ transformAnimalsToDogsWithDynamicCast i transformAnimalsToDogsWithCustomCast. 
Zmierz czas wykonywania obu metod, oraz porównaj czasy (skompiluj aplikacjê w trybie Release, bez debuggera).

5. Stwórzmy wskaŸnik typu Animal i zainicjujmy go jako nullptr. Jak zachowa siê nasza funkcja custom_dynamic_cast gdy podamy utworzony wskaŸnik jako argument?
Zabezpiecz dzia³anie funkcji przechwytuj¹c odpowiedni wyj¹tek w definicji custom_dynamic_cast. Jeœli wyj¹tek zostanie wy³apany, wyprowadŸ informacje o wyj¹tku na ekran konsoli, oraz zwróæ nullptr.
