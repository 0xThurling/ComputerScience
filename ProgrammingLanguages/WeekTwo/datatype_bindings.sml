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

fun max_constant e =
    let fun max_of_two(e1, e2) =
            let val m1 = max_constant e1
                val m2 = max_constant e2
            in
                if m1 > m2 then m1 else m2
            end
    in case e of
           Constant i => i
         | Negate e2 => max_constant e2
         | Add (e1, e2) => max_of_two(e1, e2)
         | Multiple (e1, e2) => max_of_two(e1, e2)
    end
