# This module is designed to process arguments and display the result on the screen.||
# It is the main module.                                                            ||
# It is called from C code (main.c)                                                 ||
# ==================================================================================||
# Radokhleb Valery
# Version 1.0


# ██████╗ ██████╗ ██╗  ██╗        ████████╗██████╗  █████╗  █████╗ ███████╗        ████████╗ █████╗  █████╗ ██╗
# ██╔══██╗██╔══██╗██║  ██║        ╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝        ╚══██╔══╝██╔══██╗██╔══██╗██║
# ██████╔╝██║  ██║███████║           ██║   ██████╔╝███████║██║  ╚═╝█████╗             ██║   ██║  ██║██║  ██║██║
# ██╔══██╗██║  ██║██╔══██║           ██║   ██╔══██╗██╔══██║██║  ██╗██╔══╝             ██║   ██║  ██║██║  ██║██║
# ██║  ██║██████╔╝██║  ██║           ██║   ██║  ██║██║  ██║╚█████╔╝███████╗           ██║   ╚█████╔╝╚█████╔╝███████╗
# ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝           ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚══════╝           ╚═╝    ╚════╝  ╚════╝ ╚══════╝

from performance import TraceLoad, Logo, OHandler
import sys


def main():
    try:

        # Handle args (Help command)
        if sys.argv[2] == '--help' or sys.argv[2] == '-h' and len(sys.argv) == 3:
            OHandler.show_help(sys.argv[1])

        # Handle args (Usage)
        elif len(sys.argv) != 6 and sys.argv[2] != '--help' and sys.argv[2] != '-h':
            OHandler.usage()


        else:
            try:

                # Parse args
                trace1 = sys.argv[2]
                trace2 = sys.argv[3]
                addr_column = int(sys.argv[4])
                inst_column = int(sys.argv[5])

                OHandler.check_csv_format(trace1)
                OHandler.check_csv_format(trace2)

                Tracer = TraceLoad.TraceHandler(trace1, trace2, addr_column, inst_column)
                diff_first = Tracer.makeTraceFirst()
                diff_last = Tracer.makeTraceLast()

                OHandler.make_trace_result(diff_first, 1)
                OHandler.make_trace_result(diff_last, 2)

                Logo.show_logo()
            except ValueError:
                print("\n" + " " * 10 + "[ERROR] 3 and 4 arg must be integer \n")
    except IndexError:
        print("\n" + " " * 10 + "[ERROR] Invalid args \n")
        OHandler.show_help(sys.argv[1])


if __name__ == "__main__":
    main()
