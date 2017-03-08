from fabric.api import local
def lsfab():
	local('cd ~/test')
	local('ls -l')

