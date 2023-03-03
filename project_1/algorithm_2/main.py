s1 = [['7:00', '8:30'], ['12:00', '13:00'], ['16:00', '18:00']]
da1 = ['9:00', '19:00']
s2 = [['9:00', '10:30'], ['12:20', '14:30'],
      ['14:00', '15:00'], ['16:00', '17:00']]
da2 = ['9:00', '18:30']
d = 30

# replaces each range with an integer representing
# the range as total minutes


def parse_range(t_range):
    for idx in range(2):
        h, m = [int(i) for i in t_range[idx].split(':')]
        t_range[idx] = m + 60 * h
    return t_range

# parses the schedule from strings to minutes
# and throws out any unavalabilites
# outside of the active schedule range


def parse_ranges(schedule, active):
    # first parse the schedule
    for idx in range(len(schedule)):
        schedule[idx] = parse_range(schedule[idx])
    # then the active range
    active = parse_range(active)
    # throw out any ranges that are lower than thelowest bound
    while len(schedule) > 0 and schedule[0][0] < active[0]:
        if schedule[0][1] < active[0]:
            schedule.pop(0)
        # if only the first one is lower just replace it with the lower bound
        else:
            schedule[0][0] = active[0]
    # do the same for the upper bounds
    while len(schedule) > 0 and schedule[-1][1] > active[1]:
        if schedule[-1][0] > active:
            schedule.pop()
        else:
            schedule[-1][1] = active[1]
    # finally we must ensure that the array is interanlly consitent
    # by merging any overlaping timeblocks
    i = 0
    while i < len(schedule) - 1:
        if schedule[i][1] > schedule[i+1][0]:
            schedule[i][1] = schedule[i + 1][1]
            schedule.pop(i+1)
            continue
        i += 1
    # return the modified schedule array
    return schedule

# merge s1 into s2


def merge_schedules(s1, s2, a1, a2):
    start = max(a1[0], a2[0])
    end = min(a1[1], a2[1])
    # start at the first index of s2
    # and only increment when the current value of s1 is higher
    i = 0
    while len(s1) > 0 and i < len(s2):
        # compare the first element of s1 only
        t = s1.pop(0)
        # if the start of s1 is earlier
        if t[0] < s2[i][0]:
            if t[1] < s2[i][0]:
                # and the end is earlier
                # insert it before the
                # current element of s2
                s2.insert(i, t)
            elif t[1] <= s2[i][1]:
                # and the end is later than
                # the start of the current s2
                # element but less than the end of
                # that element, then the ranges overlap
                # and combine to form a union of both ranges
                s2[i][0] = t[0]
            else:
                # otherwise the end of the s1 range must be larger
                # which means the s2 range is a subset of the s1
                # and we can simply replace the s2 range with it
                s2[0] = t
        # now check for conditions where s1 starts later than s2
        elif t[0] > s2[i][0]:
            # if s1 starts after s2 finishes
            if t[0] > s2[i][1]:
                # insert after the s2  range ONLY if
                # the following range in s2 starts later than
                # the current s1 range. Otherwise we get an
                # out of order insertion
                if t[1] < s2[i+1][0]:
                   s2.insert(i+1, t)
                else:
                    # to prevent an out of order insertion
                    # insert the s1 range back in until it
                    # can be properly ordered
                    s1.insert(0, t)
            # if s1 ends after s2, extend the current s2 range
            elif t[1] >= s2[i][1]:
                s2[i][1] = t[1]
        else:
            # if they start at the same time, we only care if
            # they dont also end at the same time, in which case we extend the current s2 range.
            if t[1] != s2[i][1]:
                if t[1] > s2[i][1]:
                    s2[i][1] = t[1]
        i += 1
    # in case s1 has items remaining
    if len(s1) > 0:
        s2.extend(s1)
    # account for common availabilities not covered
    if s2[0][0] > start:
        s2[0][0] = start
    if s2[-1][1] < end:
        s2[-1][1] = end
    return s2

# parse the output back to string/date format


def parse_availabilties(s):
    for t in s:
        for i in range(2):
            m = int(t[i] % 60)
            h = int((t[i] - m) / 60)
            if m < 10:
                m = f'0{m}'
            if h < 10:
                h = f'0{h}'
            t[i] = f'{h}:{m}'
    print(s)


s1 = parse_ranges(s1, da1)
s2 = parse_ranges(s2, da2)

s3 = merge_schedules(s1, s2, da1, da2)

parse_availabilties(s3)
