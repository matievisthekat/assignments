#!/usr/bin/perl

use strict;
use warnings;

# Use constant file name
my $file_name = "Cremation.txt";

# Check if file exists
unless (-e $file_name) {
    die "File '$file_name' not found.\n";
}

# Read file into an array of words
my @words;
open(my $fh, "<", $file_name) or die "Could not open file '$file_name': $!";
while (my $line = <$fh>) {
    chomp $line;
    # Split the line into words, remove punctuation, and convert to lowercase
    my @line_words = map { lc($_ =~ s/[^a-zA-Z\s]//gr) } split /\s+/, $line;
    push @words, @line_words;
}
close $fh;

print "Analyze Passage: $file_name\n\n";

# Remove duplicates and sort words in reverse alphabetical order
my %unique_words;
foreach my $word (@words) {
    $unique_words{$word}++;
}
my @sorted_words = sort { $b cmp $a } keys %unique_words;

# Display word list
my $num_words = scalar @sorted_words;
my $min_width = 10;
my $num_cols = 9;
my $num_rows = int($num_words / $num_cols) + ($num_words % $num_cols ? 1 : 0);
# Loop for each row of words
for (my $i = 0; $i < $num_rows; $i++) {
    my $start_index = $i * $num_cols;
    my $end_index = $start_index + $num_cols - 1;
    $end_index = $num_words - 1 if ($end_index > $num_words - 1);
    my @row_words = @sorted_words[$start_index..$end_index];
    foreach my $word (@row_words) {
        printf("%-${min_width}s", $word);
    }
    print "\n";
}
print "\nUnique words: $num_words\n";
print "Duplicate words removed: " . ($#words + 1 - $num_words) . "\n\n";
