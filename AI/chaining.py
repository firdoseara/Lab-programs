#forward_chaining
def forward_chaining(rules,facts,goal):
    while True:
        new_facts=set()
        for rule in rules:
            premise,conclusion=rule
            if all(fact in facts for fact in premise) and conclusion not in facts:
                new_facts.add(conclusion)
        if not new_facts:
            break
        facts.update(new_facts)
        if goal in facts:
            return True
    return False
rules=[(['A','B'],'C'),(['C'],'D'),(['D'],'E')]
facts={'A','B'}
goal='E'
result=forward_chaining(rules,facts,goal)
print("Goal'{}'can{}be reached using forward chaining.".format(goal,' 'if result else 'not'))

#backward_chaining
def backward_chaining(rules,facts,goal):
    if goal in facts:
        return True
    for rule in rules:
        premise,conclusion=rule
        if conclusion==goal:
            if all(backward_chaining(rules,facts,fact)for fact in premise):
                return True
    return False
rules=[(['A','B'],'C'),(['C'],'D'),(['D'],'E')]
facts={'A','B'}
goal='E'
result=backward_chaining(rules,facts,goal)
print("Goal'{}'can{}be reached using backward chaining.".format(goal,' 'if result else 'not'))
