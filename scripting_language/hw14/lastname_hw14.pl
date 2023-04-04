use strict;
use warnings;
use v5.10.0;
use Time::HiRes qw( time );
use IO::Handle;
use POSIX;

STDOUT->autoflush(1);    # Turn off stdout buffering

# Parse command-line arguments
my ($filename, $count) = @ARGV;

# Check for correct usage
if (not defined $filename or not defined $count) {
    say "Usage: perl CreateBigData.pl filename count";
    exit 1;
}

# Check count is within the valid range
if ($count < 1 or $count > 100_000_000) {
    say "Count must be between 1 and 100 million";
    exit 1;
}

my $startTime = time();    # Capture start time

# Open the output file
open(my $out, '>', $filename)
    or die "Cannot create file $filename: $!";

# Generate and write random integers to file
foreach my $i (1..$count) {
    my $rand_int = int(rand(1_000_000_000)) + 1;
    print $out "$rand_int\n";
}

close $out;

printf("Creating file %s with %s random ints\n\n", $filename, commify($count));

my $elapsed = time() - $startTime;    # Calculate elapsed time

# Print timing results
printf("Elapsed time to create %s (%s values):\n\n", $filename, commify($count));

my $min = $elapsed / 60;
my $sec = $elapsed;
my $ms  = $elapsed * 1000;

printf("%0.3f minutes\n", $min);
printf("%0.3f seconds\n", $sec);
printf("%0.1f milliseconds\n\n", $ms);

printf("Done\n\n");

# This function produces a comma-separated string for a given number
# Usage: commify(1234567) -> 1,234,567
sub commify {
    local($_) = int(shift);
    1 while s/^(-?\d+)(\d{3})/$1,$2/;
    return $_;
}
