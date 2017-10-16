# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure("2") do |config|
  
   config.vm.define :ubuntu do |ubuntu|
    ubuntu.vm.provider "virtualbox" do |v|
          v.customize ["modifyvm", :id, "--name", "ubuntu", "--memory", "512"]
    end
    ubuntu.vm.box = "laravel/homestead"
    ubuntu.vm.hostname = "ubuntu"
    ubuntu.vm.network :private_network, ip: "192.168.33.10"
    ubuntu.vm.synced_folder "E:\\ClionProjects", "/home/vagrant/cproject"
    #ubuntu.vm.synced_folder "E:\\ClionProjects", "/home/vagrant"

  end

  config.vm.define :l1 do |l1|
    l1.vm.provider "virtualbox" do |v|
          v.customize ["modifyvm", :id, "--name", "ubuntu1", "--memory", "512"]
    end
    l1.vm.box = "laravel/homestead"
    l1.vm.hostname = "u1"
    l1.vm.network :private_network, ip: "192.168.33.11"
    l1.vm.synced_folder "E:\\ClionProjects", "/home/vagrant/cproject"
  end

  config.vm.define :l2 do |l2|
    l2.vm.provider "virtualbox" do |v|
          v.customize ["modifyvm", :id, "--name", "ubuntu2", "--memory", "512"]
    end
    l2.vm.box = "laravel/homestead"
    l2.vm.hostname = "u2"
    l2.vm.network :private_network, ip: "192.168.33.12"
    l2.vm.synced_folder "E:\\ClionProjects", "/home/vagrant/cproject"
  end

  config.vm.define :jessie do |jessie|
    jessie.vm.provider "virtualbox" do |v|
          v.customize ["modifyvm", :id, "--name", "jessie", "--memory", "512"]
    end
    jessie.vm.box = "debian/jessie64"
    jessie.vm.hostname = "debian"
    jessie.vm.network :private_network, ip: "192.168.33.9"
    #jessie.vm.synced_folder "E:\\ClionProjects", "/home/vagrant/cproject"
  end
  config.vm.define :debian do |debian|
    debian.vm.provider "virtualbox" do |v|
          v.customize ["modifyvm", :id, "--name", "debian", "--memory", "512"]
    end
    # debian.vm.box = "debian/jessie64"
    debian.vm.box = "debian/contrib-jessie64"
    debian.vm.hostname = "debian"
    debian.vm.network :public_network, ip: "192.168.10.210"
    debian.vm.network :private_network, ip: "192.168.33.13"
    debian.vm.synced_folder "E:\\ClionProjects", "/home/vagrant/cproject"
  end
  config.vm.define :debian2 do |debian2|
    debian2.vm.provider "virtualbox" do |v|
          v.customize ["modifyvm", :id, "--name", "debian2", "--memory", "512"]
    end
    # debian2.vm.box = "debian/jessie64"
    debian2.vm.box = "debian/contrib-jessie64"
    debian2.vm.hostname = "debian2"
    debian2.vm.network :public_network, ip: "192.168.10.211"
    debian2.vm.network :private_network, ip: "192.168.33.14"
    debian2.vm.network :private_network, ip: "10.158.175.238"
    debian2.vm.synced_folder "E:\\ClionProjects", "/home/vagrant/cproject"
  end

end
