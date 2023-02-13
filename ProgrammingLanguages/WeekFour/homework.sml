(* Coursera Programming Languages, Homework 3, Provided Code *)

exception NoAnswer

datatype pattern = Wildcard
		 | Variable of string
		 | UnitP
		 | ConstP of int
		 | TupleP of pattern list
		 | ConstructorP of string * pattern

datatype valu = Const of int
	      | Unit
	      | Tuple of valu list
	      | Constructor of string * valu

fun g f1 f2 p =
    let 
	val r = g f1 f2 
    in
	case p of
	    Wildcard          => f1 ()
	  | Variable x        => f2 x
	  | TupleP ps         => List.foldl (fn (p,i) => (r p) + i) 0 ps
	  | ConstructorP(_,p) => r p
	  | _                 => 0
    end

(**** for the challenge problem only ****)

datatype typ = Anything
	     | UnitT
	     | IntT
	     | TupleT of typ list
	     | Datatype of string

(**** you can put all your code here ****)

fun f s = Char.isUpper(String.sub(s, 0))
fun only_capitals letters = List.filter f letters      

fun longest_string1 (words: string list) =
  List.foldl (fn (x, y) => if String.size x > String.size y then x else y) "" words

fun longest_string2 (words: string list) = 
  List.foldl (fn (x, y) => if String.size x < String.size y then x else y) "" words

fun longest_string_helper f words = List.foldl f "" words
fun longest_string3 words = 
  longest_string_helper (fn (x, y) => if String.size x > String.size y then x
                                      else y) words


fun longest_capitalized words = 
  let val xs = only_capitals words in 
    List.foldl (fn (x, y) => if String.size x > String.size y then x else y) "" xs
  end

fun rev_string word = String.implode o List.rev o String.explode
