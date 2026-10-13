class animals:
    print("This is a super class")
    a=10
class pets(animals):
    print("This is a child class")
class dogs(pets):
    print("This is called multilevelinheritance")
    def  bark(self):
        print()
object=dogs()
object.bark()
        