import pytholog as pl

new_kb=pl.knowledge_base("facts")
new_kb(["likes(shyam,mango)",
        "likes(bill,cindy)",
        "girl(seema)",
        "red(rose)",
        "owns(john,gold)",
        ])

print(new_kb.query(pl.Expr("likes(bill,russian)")))