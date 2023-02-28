def parse_range(t_range):
    ret = []
    for t in t_range:
        mins = 0
        h, m = t.split(':')
        mins += int(m)
        mins += 60 * int(h)
        ret.append(mins)
    return ret

def parse_schedule(sch):
    for i, s in enumerate(sch):
        sch[i] = parse_range(s)
    return sch

print(parse_schedule(schedule_2))

