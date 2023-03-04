import os
import re

def main():
  print("Command Processor\n")

  inp = None
  while inp == None:
    inp = input("Name of input file: ")
    if not inp.endswith(".txt"):
      inp = f"{inp}.txt"

    if not os.path.isfile(inp):
      print(f"Operation failed: No such file {inp}")
      inp = None

  out = None
  while out == None:
    out = input("Name of output file: ")
    if not out.endswith(".txt"):
      out = f"{out}.txt"

    if not os.access(out, os.W_OK):
      print(f"Operation failed: Unable to access file {out}")
      out = None

  with open(inp, "r") as i:
    with open(out, "w") as o:
      for i_line in i:
        i_line = i_line.strip()
        args = [arg for arg in re.split('\\s+', i_line) if arg]
        
        if len(args) < 3:
          continue

        op = args[0].lower()
        values = args[1:]
        res = None
        output = f"{op}({values[0]}, {values[1]}) = "

        val1 = makeSureIsInt(values[0])
        if isinstance(val1, Error):
          output += val1.msg
        else:
          val2 = makeSureIsInt(values[1])
          if isinstance(val2, Error):
            output += val2.msg
          else:
            if op == "add":
              output += f"{val1 + val2}"
            elif op == "sub":
              output += f"{val1 - val2}"
            elif op == "multiply":
              output += f"{val1 * val2}"
            elif op == "divide":
              try:
                output += f"{val1 / val2}"
              except ZeroDivisionError:
                output += f"Cannot divide by zero"
            elif op == "power":
              output += f"{val1 ** val2}"
            else:
              output += f"'{op}' is not a command"

        o.write(output + "\n")

      o.close()
      i.close()
      print("\nDone!")
        



def makeSureIsInt(str):
  try:
    i = float(str)
    return i
  except:
    return Error(f"Expected string '{str}' to be a number. It is not")

class Error:
  def __init__(self, msg):
    self.msg = msg

if __name__ == "__main__":
  main()
