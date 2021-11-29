# Project name: 
Multi-Threaded-Task-Scheduler

# Description:
Implementing a system that automatically executes scheduled tasks. 
The execution time of the tasks described in a csv configuration file
The system loads the tasks description from the csv configuration file and executes them
automatically on the scheduled time.
The addition of new tasks is simply by adding new line to the CSV file configuration.

# Multi-threading - 
The tasks can run simultaneously

# CSV file structure:
Each task describe by:
minute,hour,day_of_week,command

# Values range:
• Minute: 0-59
• Hour: 0-23
• Day of week: 0-6, where 0 = Monday, 6 = Sunday
• Command: text

# Execution:
The project was written & compiled in Visual Studio
