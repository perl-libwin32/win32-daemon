use strict;
use warnings;
use Test::More;
use Win32::Daemon;

# Needs an update when Win32::Daemon::EXPORT count changes
plan tests => 63;

my %vals;
foreach my $to_export (@Win32::Daemon::EXPORT)
{
	like(eval("Win32::Daemon::$to_export; 'ok'") || $@,
		 qr/^(ok|Your vendor has not defined 'Win32::Daemon' macro.*)$/,
		 "$to_export");

	$vals{$to_export} = eval("Win32::Daemon::$to_export;") || $@;
}

# Uncomment these to see the list of values and possible exceptions
#use Data::Dumper;
#$Data::Dumper::Sortkeys = 1;
#print Dumper(\%vals);
