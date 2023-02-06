datatype mytype = TwoInts of int * int
       | Str of string
       | Pizza

val a = Str "hi"
val b = Str
val c = Pizza
val d = TwoInts(1+2, 2+3)
val e = a

	     
fun f x = case x of
              Pizza => 3
           | Str s => 8
           | TwoInts(i1, i2) => i1 + i2

datatype exp = Constant of int
       | Negate of exp
       | Add of exp * exp
       | Multiply of exp * exp

fun number_of_adds e = case e of
                Constant i => 0
              | Negate n => number_of_adds n
              | Add(e1,e2) => 1 + number_of_adds e1 + number_of_adds e2
              | Multiply(e1,e2) => number_of_adds e1 + number_of_adds e2
