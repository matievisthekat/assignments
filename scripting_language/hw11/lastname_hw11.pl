#!/usr/bin/perl

use strict;
use warnings;

sub Collatz {
    my ($n) = @_;
    my @seq = ($n);
    while ($n > 1) {
        # if n is even
        if ($n % 2 == 0) {
            $n = $n / 2;
        } else {
            $n = 3 * $n + 1;
        }
        push @seq, $n;
    }
    return @seq;
}

my $n = 1;
while (1) {
    # get array from function
    my @seq = Collatz($n);
    my $len = scalar @seq;
    # if the array is long enough, print info and exit the loop
    if ($len >= 10) {
        print "The First Collatz Sequence with Length >= 10 is Collatz(" . $n . ") with length = " . $len . ":\n\t";
        print join("\t", @seq) . "\n\n";
        last;
    }
    $n++;
}

$n = 1;
while (1) {
    # get array from function
    my @seq = Collatz($n);
    my $len = scalar @seq;
    # if the array is long enough, print info and exit the loop
    if ($len >= 24) {
        print "The First Collatz Sequence with Length >= 24 is Collatz(" . $n . ") with length = " . $len . ":\n\t";
        print join("\t", @seq) . "\n\n";
        last;
    }
    $n++;
}

$n = 1;
while (1) {
    # get array from function
    my @seq = Collatz($n);
    my $len = scalar @seq;
    # if the array is long enough, print info and exit the loop
    if ($len >= 100) {
        print "The First Collatz Sequence with Length >= 100 is Collatz(" . $n . ") with length = " . $len . ":\n\t";
        print join("\t", @seq) . "\n\n";
        last;
    }
    $n++;
}

$n = 1;
while (1) {
    # get array from function
    my @seq = Collatz($n);
    my $len = scalar @seq;
    # if the array is long enough, print info and exit the loop
    if ($len >= 200) {
        print "The First Collatz Sequence with Length >= 200 is Collatz(" . $n . ") with length = " . $len . ":\n\t";
        print join("\t", @seq) . "\n\n";
        last;
    }
    $n++;
}
