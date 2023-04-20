'''
Write a program in prolog/pytholog to implement following simple facts and Queries
Every child loves Santa.
Everyone who loves Santa loves any reindeer
Rudolph is a reindeer, and Rudolph has a red nose
Anything which has a red nose is weird or is a clown
No reindeer is a clown
Scrooge does not love anything which is weird
(Conclusion) Scrooge is not a child.
'''
# V.Nagasai CS20B1016
import pytholog as pl

kb=pl.KnowledgeBase("logic")
kb(["child_loves(X) :- child(X), loves(X, santa).",
    "loves(X, santa) :- child(X).",
    "loves(X, Y) :- loves(X, santa), reindeer(Y).",
    "reindeer(rudolph).",
    "has_red_nose(rudolph).",
    "weird(X) :- has_red_nose(X) ; clown(X).",
    "not(clown(X)) :- reindeer(X).",
    "not_loves_scrooge(X) :- scrooge(Y), weird(X), loves(Y, X).",
    "scrooge(scrooge)."])

result = kb.query(pl.Expr("not(child(scrooge))"))

if result==['YES']:
    print("Scrooge is child")
else:
    print("scrooge is not child")