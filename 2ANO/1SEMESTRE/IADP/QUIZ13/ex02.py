def dechours_to_hms(value):
    hours = int(value)

    remaining_minutes = (value - hours) * 60
    minutes = int(remaining_minutes)

    seconds = round((remaining_minutes - minutes) * 60)

    return f"{hours} hours, {minutes} minutes, {seconds} seconds"

print(dechours_to_hms(72.345))