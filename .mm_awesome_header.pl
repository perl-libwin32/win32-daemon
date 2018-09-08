use Config qw(%Config);
require Win32;

# Sorry, we can't support cygwin right now. We'd love for you to fix the
# compilation problems and submit a PR to get it back, though!!
unless ($^O eq "MSWin32") { # || $^O eq "cygwin") {
    die "OS unsupported\n";
}

my %xsbuild = (
    XS => { 'Daemon.xs' => 'Daemon.cpp', },
    OBJECT  => 'CCallbackList$(OBJ_EXT) CCallbackTimer$(OBJ_EXT) constant$(OBJ_EXT) CWinStation$(OBJ_EXT) Daemon$(OBJ_EXT) ServiceThread$(OBJ_EXT)',
);
$xsbuild{NO_META} = 1 if eval { ExtUtils::MakeMaker->VERSION('6.10_03') };
$xsbuild{INC} .= ' -EHsc' if $Config{'cc'} =~ /^cl/i;

sub MY::xs_c {
    '
.xs.cpp:
	$(PERL) -I$(PERL_ARCHLIB) -I$(PERL_LIB) $(XSUBPP) $(XSPROTOARG) $(XSUBPPARGS) $*.xs >xstmp.c && $(MV) xstmp.c $*.cpp
';
}
