# This module is designed for parsing CSV files||
# and calculating the difference               ||
# in traces addresses                          ||
# =============================================||
# Radokhleb Valery
# Version 1.0
import csv


class TraceHandler:
    def __init__(self, trace1=None, trace2=None, addr_column=int(), asm_column=int()):
        self.trace1 = trace1
        self.trace2 = trace2
        self.addr_column = addr_column
        self.inst_column = asm_column

        # Make Addr flat list
        self.traceFirstList = list()
        self.traceLastList = list()
        self.addrFirstList = list()
        self.addrLastList = list()
        try:
            with open(trace1, 'r') as t1:
                reader = csv.reader(t1)
                for row in reader:
                    self.traceFirstList.append(row)
                    self.addrFirstList.append(row[addr_column - 1])

            with open(trace2, 'r') as t2:
                reader = csv.reader(t2)
                for row in reader:
                    self.traceLastList.append(row)
                    self.addrLastList.append(row[addr_column - 1])

        except FileNotFoundError as e:
            print(f"[ERROR] File {e} not found")
            exit()

    def makeTraceFirst(self=None):
        addr_difference = list()
        for addr in self.traceFirstList:
            if str(addr[1]) not in self.addrLastList:
                chunk = list()
                chunk.append(addr[self.addr_column - 1])
                chunk.append(addr[self.inst_column - 1])
                addr_difference.append(chunk)

        return addr_difference

    def makeTraceLast(self=None):
        addr_difference = list()
        for addr in self.traceLastList:
            if str(addr[self.addr_column - 1]) not in self.addrFirstList:
                chunk = list()
                chunk.append(addr[self.addr_column - 1])
                chunk.append(addr[self.inst_column - 1])
                addr_difference.append(chunk)

        return addr_difference
