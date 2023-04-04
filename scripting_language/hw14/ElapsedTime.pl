# ElapsedTime.pl - Calculate elapsed time for a calculation

use strict;
use warnings;
use v5.10.0;
use Time::HiRes qw( time );
use IO::Handle;

STDOUT->autoflush(1);                           # Turn off stdout buffering

my $REPS = 50_000_000;                          # Number of repetitions

say "\nCalculate elapsed time for " . commify($REPS) . " repetitions\n";

my $startTime = time();							# Capture start time

# Stuff you want to time goes here:
foreach my $x (0..$REPS) {
	my $y = $x ** 2;
	if ($x % 500_000 == 0) { print "."; }		# Periodically print periods 
}
say "\n";

my $elapsed = time() - $startTime;				# Calculate elapsed time

printf("%0.3f minutes\n", $elapsed / 60);
printf("%0.3f seconds\n", $elapsed);
printf("%0.1f milliseconds\n", $elapsed * 1000);
my $mcs = commify($elapsed * 1000 * 1000);
printf("%s microseconds\n", $mcs);

say "\nDone\n";

##################################

# This function produces a comma-separated string for a given number
# Usage: commify(1234567) -> 1,234,567

sub commify {
    local($_) = int(shift);
    1 while s/^(-?\d+)(\d{3})/$1,$2/;
    return $_;
}

##################################