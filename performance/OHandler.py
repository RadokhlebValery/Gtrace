# The module is intended for outputting reference (help) information.            ||
# The module is also designed to output help information when handling exceptions||
# ===============================================================================||
# Radokhleb Valery
# Version 1.0
import os

trace1_out = "=[DIFF Trace 1 => Trace 2]="
trace2_out = "=[DIFF Trace 2 => Trace 1]="
no_diff = "=[NO TRACE DIFFERENCE]="

# Show txt help file
def show_help(path_to_help_file):
    try:
        file_name, file_format = os.path.splitext(path_to_help_file)
        if file_format != ".txt":
            print(f"[ERROR] Help file {file_name} is not in TXT format")
            exit()
        else:
            with open(path_to_help_file, "r") as help:
                print(help.read())
                exit()

    except FileNotFoundError as e:
        print(f"[ERROR] File: {e} do not exist")
        exit()


# Trace out
def make_trace_result(display_list, mode):
    trace_queue_info = str()
    if mode == 1:
        trace_queue_info = trace1_out
    elif mode == 2:
        trace_queue_info = trace2_out
    else:
        print("\n" + " " * 10 + "[ERROR] No mode found")

    if len(display_list) == 0:
        print("\n" + " " * 10 + f"{trace_queue_info} \n")
        print("\n" + " " * 10 + f"{no_diff} \n")
    else:
        print("\n" + " " * 10 + f"{trace_queue_info} \n")
        for chunk in display_list:
            print(" " * 10 + f"{chunk[0]} |" + f"| {chunk[1]}")


# Check CSV format
def check_csv_format(file):
    file_name, ex_name = os.path.splitext(file)
    if ex_name != ".csv":
        print("\n" + " " * 10 + f"[ERROR] File {file_name} is not in CSV format")
        exit()

# Show usage
def usage():
    print("[USAGE] there must be 4 arguments !")
    exit()