def count_word_frequencies(text):
    # Initialize an empty dictionary for word frequencies
    word_frequencies = {}
    # Split the text into words and loop over each word
    for word in text.split():
        # Remove all punctuation from the word by iterating over each character
        # and skipping punctuation characters
        word_without_punct = ""
        for char in word:
            if char.isalnum() or char.isspace():
                word_without_punct += char
        # Convert the word to lowercase
        word_without_punct = word_without_punct.lower()
        # If the word is not empty, update its frequency count in the dictionary
        if word_without_punct:
            word_frequencies[word_without_punct] = word_frequencies.get(word_without_punct, 0) + 1
    # Return the dictionary of word frequencies
    return word_frequencies

def main():
    text = "The quick brown fox jumps over the lazy dog. The dog barks and the fox runs away."
    word_frequencies = count_word_frequencies(text)
    print(word_frequencies)

if __name__ == "__main__":
    main()