sub piglatin {
    my $word = shift;
    if ($word =~ /^([aeiou]|y[^aeiou]*)/i) {
        # Word begins with a vowel or vowel group
        return $word . "yay";
    } elsif ($word =~ /^([^aeiouy]+)(.*)/i) {
        # Word begins with a consonant or consonant group
        my $consonants = $1;
        my $rest = $2;
        return $rest . $consonants . "ay";
    } else {
        # Word doesn't match either pattern (shouldn't happen)
        return $word;
    }
}

print "Pig Latin Translator\n";
print "--------------------\n\n";

# Get file name from user
print "Enter file name: ";
my $filename = <STDIN>;
chomp($filename);

print "\nOrigintal Text (from $filename):\n\n";

# Open file and read contents
open(my $fh, '<', $filename) or die "Can't open file '$filename': $!";
my $text = "";
while (my $line = <$fh>) {
    $text .= $line;
}
close($fh);

print "$text";

# Translate text to Pig Latin
my @words = split(/(\W+)/, $text); # Split text into words and punctuation
my $piglatin_text = "";
foreach my $word (@words) {
    if ($word =~ /^[a-zA-Z]+$/) {
        # Word contains only letters
        my $piglatin_word = piglatin($word);
        $piglatin_word = ucfirst($piglatin_word) if ($word =~ /^[A-Z]/);
        $piglatin_text .= $piglatin_word;
    } else {
        # Word contains punctuation or whitespace
        $piglatin_text .= $word;
    }
}

# Display translated text
print "\n\nTranslated Text:\n\n";
print $piglatin_text;

print "\n\nDone\n";
