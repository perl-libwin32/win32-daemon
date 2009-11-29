use strict;
use warnings;

use Config qw(%Config);
use ExtUtils::MakeMaker;

unless ($^O eq "MSWin32" || $^O eq "cygwin") {
    die "OS unsupported\n";
}

require Win32;

my %param = (
    NAME          => 'Win32::Daemon',
    VERSION_FROM  => 'Daemon.pm',
    DEFINE        => '-DPERL5010 -DSERVICE_CONTROL_DEVICEEVENT=0x0b -DSERVICE_CONTROL_HARDWAREPROFILECHANGE=0x0c -DSERVICE_CONTROL_POWEREVENT=0x0d -DSERVICE_CONTROL_SESSIONCHANGE=0x0e',
    INC           => '-I.',
    OBJECT        => 'CCallbackList$(OBJ_EXT) CCallbackTimer$(OBJ_EXT) Constant$(OBJ_EXT) CWinStation$(OBJ_EXT) Daemon$(OBJ_EXT) ServiceThread$(OBJ_EXT)',
    XS            => { 'Daemon.xs' => 'Daemon.cpp' },
);
$param{INC}     .= ' -GX' if $Config{'cc'} =~ /^cl/i;
WriteMakefile(%param);

sub MY::xs_c {
    '
.xs.cpp:
	$(PERL) -I$(PERL_ARCHLIB) -I$(PERL_LIB) $(XSUBPP) $(XSPROTOARG) $(XSUBPPARGS) $*.xs >xstmp.c && $(MV) xstmp.c $*.cpp
';
}
