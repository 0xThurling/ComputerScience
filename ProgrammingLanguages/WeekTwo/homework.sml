(* Dan Grossman, Coursera PL, HW2 Provided Code *)

(* if you use this function to compare two strings (returns true if the same
   string), then you avoid several of the functions in problem 1 having
   polymorphic types that may be confusing *)
fun same_string(s1 : string, s2 : string) =
    s1 = s2

(* put your solutions for problem 1 here *)

(* you may assume that Num is always used with values 2, 3, ..., 10
   though it will not really come up *)
datatype suit = Clubs | Diamonds | Hearts | Spades
datatype rank = Jack | Queen | King | Ace | Num of int
type card = suit * rank

datatype color = Red | Black
datatype move = Discard of card | Draw

exception IllegalMove

(* put your solutions for problem 2 *)

fun all_except_option tuple =
    let
	fun does_contain_values values =
	    case values of
		((w, []), false) => false
	      | (_, true) => true 
	      | ((w, x::xs), _) => case same_string(w, x) of
				       true => does_contain_values((w,xs), true)
				     | false => does_contain_values((w, xs), false)

	fun get_list (value) =
	    case value of
		(w, []) => []
	      | (w, x::xs)  => case same_string(w,x) of
				  true => xs
				| false => x::get_list(w, xs) 
    in
        case does_contain_values(tuple, false) of
	    true => get_list(tuple)
	  | false => []
    end
	
fun get_substitutions1 (word_lists, word) =
    case word_lists of
        x::xs => all_except_option(word, x) @ get_substitutions1 (xs, word)
      | _ => [] 

fun similar_names (word_list, record) =
    let
	fun cons_records(words, record) =
	    case words of
		[] => []
	      | x::xs => case record of
			     {first=a,middle=b,last=c} =>
			          [{first=x, middle=b, last=c}] @ cons_records(xs, record)
    in 
	case record of
	    {first=a,middle=b,last=c} => case get_substitutions1 (word_list, a) of
					     [] => []
					   | x::xs => [record] @ [{first=x, middle=b,last=c}] @ cons_records(xs, record)
    end
	
	 
fun card_color card =
    case card of
	(s, r) => case s of
		      Clubs => Black
		    | Spades => Black
		    | Diamonds => Red
		    | Hearts => Red

fun card_value card =
    case card of
	(s,Num n) => n 
      | (s,Ace) => 11 
      | (s,_) => 10 
		  
fun remove_card (cards, card, e) =
    let
	fun same_card (c1, c2) =
	    c1 = c2

	fun remove_from_list (cards, card, removed) =
	    case cards of
		[] => []
	      | x::xs => case same_card (x, card) of
			     true => (case removed of
					 false => [] @ remove_from_list(xs, x, true)
				       | true => x::remove_from_list(xs, x, true))
			   | false => x::remove_from_list(xs, x, false)

	fun is_in_list (cards_values) =
	    case cards_values of
		(([], c), false) => false
	      | (_, true) => true
	      | ((x::xs, c),false) => case same_card(x, c) of
					  true => is_in_list ((xs,c), true)
					| false => is_in_list ((xs,c), false) 
	    
    in
	case is_in_list ((cards, card), false) of
	    true => remove_from_list (cards, card, false)
	  | false => raise e 
    end

fun all_same_color (cards) =
    let
	fun same_color card_tuple =
	    case card_tuple of
		([],c, true) => true
	      | (_, c,false) => false 
	      | (x::xs,c, true) => case card_color(x) = card_color(c) of
				    true => same_color(xs,x,true)
				  | false => same_color(xs,x,false) 
    in
	case cards of
	    x::xs => same_color (xs, x, true)
	  | _ => false
    end

fun sum_cards (cards) =
    let
	fun sum (cards, acc) =
	    case cards of
		[] => acc
	      | x::xs => sum(xs, acc + card_value(x)) 
    in
	sum(cards, 0)
    end
