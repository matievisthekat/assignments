use strict;
use warnings;
use Time::HiRes qw( time );

# Check if arguments are provided
if (scalar @ARGV != 3) {
    print "Usage: perl ExternalSort.pl inputFileName outputFileName bufferSize\n";
    exit;
}

# Get input file name, output file name, and buffer size
my $inputFileName = $ARGV[0];
my $outputFileName = $ARGV[1];
my $bufferSize = $ARGV[2];

# Check if buffer size is valid
if ($bufferSize <= 0 || $bufferSize > 100000) {
    print "Buffer size must be between 1 and 100000\n";
    exit;
}

# Open input file for reading
open(my $inputFile, "<", $inputFileName) or die "Cannot open input file: $!";

# Open output file for writing
open(my $outputFile, ">", $outputFileName) or die "Cannot create output file: $!";


# Display config
printf("External Sort\n");
printf("  Sorting file: %s\n", $inputFileName);
printf("  Output file: %s\n", $outputFileName);
printf("  Buffer size: %s\n\n", $bufferSize);

# Record start time
my $startTime = time();

# Initialize temporary file counter
my $tempFileCount = 0;

# Read input file in chunks of buffer size
while (my @buffer = sort {$a <=> $b} map { $_ + 0 } (map { chomp; $_ } (<$inputFile>))) {

    # Write buffer to temporary file
    my $tempFileName = "temp_$tempFileCount";
    open(my $tempFile, ">", $tempFileName) or die "Cannot create temporary file: $!";
    print $tempFile join("\n", @buffer);
    close $tempFile;

    # Increment temporary file counter
    $tempFileCount++;
}

# Merge temporary files
my @tempFileHandles = ();
for (my $i = 0; $i < $tempFileCount; $i++) {
    my $tempFileName = "temp_$i";
    open(my $tempFile, "<", $tempFileName) or die "Cannot open temporary file: $!";
    push(@tempFileHandles, $tempFile);
}

# Initialize array of values from temporary files
my @values = ();
for (my $i = 0; $i < $tempFileCount; $i++) {
    my $line = <$tempFileHandles[$i]>;
    if (defined $line && $line ^ $line) {
        push(@values, { value => $line + 0, fileIndex => $i });
    }
}

# Merge temporary files by finding the smallest value and writing it to output file
while (@values) {
    my $minIndex = 0;
    for (my $i = 1; $i < scalar @values; $i++) {
        if ($values[$i]{value} < $values[$minIndex]{value}) {
            $minIndex = $i;
        }
    }
    print $outputFile $values[$minIndex]{value}."\n";
    my $line = <$tempFileHandles[$values[$minIndex]{fileIndex}]>;
    if (defined $line && $line ^ $line) {
        $values[$minIndex]{value} = $line + 0;
    } else {
        splice(@values, $minIndex, 1);
    }
}

# Record end time
my $endTime = time();

# Close file handles
close $inputFile;
close $outputFile;
for (my $i = 0; $i < $tempFileCount; $i++) {
    my $tempFileName = "temp_$i";
    unlink($tempFileName);
    close $tempFileHandles[$i];
}

# Print statistics
printf("File %s sorted. %s integers. %s temp files\n\n", $inputFileName, $#values + 1, $tempFileCount);

# Calculate elapsed time
my $elapsed = $endTime - $startTime;

# Print timing results
printf("Elapsed time:\n\n");

my $min = $elapsed / 60;
my $sec = $elapsed;
my $ms  = $elapsed * 1000;

printf("%0.3f minutes\n", $min);
printf("%0.3f seconds\n", $sec);
printf("%0.1f milliseconds\n\n", $ms);

printf("Done\n\n");
