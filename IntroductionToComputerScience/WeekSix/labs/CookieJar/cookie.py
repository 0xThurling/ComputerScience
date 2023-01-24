class Jar:
    def __init__(self, capacity=12):
        try:
            if capacity > 0:
                self.capacity = capacity
                self.size = 0
            else:
                raise ValueError
        except ValueError:
            print("This is non-positive number")

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        if self.size < self.capacity:
            self.size = self.size + n
        

    def withdraw(self, n):
        self.size  = self.size - n
        if self.size < 0:
            self.size = 0

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, value):
        self._capacity = value

    @property
    def size(self):
        return self._size 

    @size.setter
    def size(self, value):
        self._size = value 

def main():
    jar = Jar()

    print(f"Capacity: {jar.capacity}")

    jar.deposit(3)
    print("Size: " + str(jar))

    jar.withdraw(1)
    print("Size: " + str(jar))

main()