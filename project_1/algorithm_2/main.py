schedule_1 = [['7:00', '8:30'], ['12:00', '13:00'], ['16:00', '18:00']]
active_1 = ['9:00', '19:00']

schedule_2 = [['9:00', '10:30'], ['12:20', '14:30'], ['14:00', '15:00'], ['16:00', '17:00']]
active_2 = ['9:00', '18:30']

duration = 30

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

