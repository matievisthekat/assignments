vowels = "aeiouAEIOU"
consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"
letters = vowels + consonants

def piglatin(word):
    if word[0] in vowels:
        return f"{word}yay"
    else:
        consonant_group = ""
        for letter in word:
            if letter in consonants:
                consonant_group += letter
            else:
                break
        rest_of_word = word[len(consonant_group):]
        if consonant_group[0].isupper():
          rest_of_word = f"{rest_of_word[0].upper()}{rest_of_word[1:]}" if len(rest_of_word) > 1 else rest_of_word.upper()
        return f"{rest_of_word}{consonant_group.lower()}ay"


def main():
    file_name = input("Enter a file name: ")
    try:
        with open(file_name) as f:
            contents = f.read()
    except FileNotFoundError:
        print(f"Error: File {file_name} not found")
        return

    translated_contents = ""
    word = ""
    for char in contents:
      if not char in letters:
        if len(word) > 0:
          translated_contents += piglatin(word)
          word = ""

        translated_contents += char
      else:
        word += char
        

    print("Pig Latin Translator")
    print("-" * 20)
    print("")
    print(f"Original Text (from {file_name}):")
    print("")
    print(contents)
    print("")
    print("Translated Text:")
    print("")
    print(translated_contents)
    print("")
    print("Done")

if __name__ == "__main__":
    main()