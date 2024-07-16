from sympy import symbols, Or, Not

def resolution(clause1, clause2):
    resolved = False
    new_clause = None
    for literal in clause1:
        if Not(literal) in clause2:
            resolved=True
            new_clause=Or([l for l in clause1 if l != literal]+[l for l in clause2 if l != Not(literal)])
            break
    return resolved,new_clause

def resolution_algorithm(clauses):
    new_clauses = set(clauses)
    while True:
        new_clauses_size = len(new_clauses)
        for clause1 in new_clauses:
            for clause2 in new_clauses:
                if clause1 != clause2:
                    resolved, new_clause = resolution(clause1, clause2)
                    if resolved and new_clause != False:
                        new_clauses.add(new_clause)
                if len(new_clauses) == new_clauses_size:
                    break
            return new_clauses
    
if __name__ == "__main__":
    A, B, C, D = symbols('A B C D')
    clauses = [
        Or(A, B, C),
        Or(Not(A), D),
        Or(Not(B), Not(C)),
        Or(Not(D))
    ]
    new_clauses = resolution_algorithm(clauses)
    print("Resulting Clauses after Resolution:")
    for clause in new_clauses:
        print(clause)
