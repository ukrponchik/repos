module f;

import std.stdio;

/// TimeOfDay
struct TimeOfDay
{
    int hour; /// hours of day
    int minute; /// minutes of day
}

/// struct Meeting
struct Meeting
{
    string topic; /// topic
    size_t attendanceCount; /// attendance count
    TimeOfDay start; /// start time
    TimeOfDay end; /// end time
}


/**
  * Returns new duration time
  *
  * Params:
  *     start = start time
  *     duration = duration time
  */
TimeOfDay addDuration(TimeOfDay start, TimeOfDay duration)
{
    TimeOfDay result;

    result.minute = start.minute + duration.minute;
}

void main()
{
}
