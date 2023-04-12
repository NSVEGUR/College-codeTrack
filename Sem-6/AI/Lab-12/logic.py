import pytholog as pl

new_knowledge_base = pl.KnowledgeBase("ai")

new_knowledge_base([
    "likes(shyam, mango)",
    "girl(seema)",
    "likes(bill, cindy)",
    "red(rose)",
    "owns(john, gold)",
    "likes(ram, mango)"
])

print(new_knowledge_base.query(pl.Expr("likes(ram, What)")))