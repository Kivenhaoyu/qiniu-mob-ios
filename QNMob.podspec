Pod::Spec.new do |s|
  s.name         = 'QNMob'
  s.version      = '1.0.0'
  s.summary      = 'Qiniu Mobile Services SDK for iOS.'

  s.description  = 'The Mobile SDK for iOS provides a library, code samples, and documentation for developers to build connected mobile applications using Qiniu Mobile Services.'

  s.homepage     = 'https://github.com/qiniu-mob/qiniu-mob-ios'
  s.license      = 'Apache License, Version 2.0'
  s.author       = { 'Qiniu Mobile Services' => 'qiniumobileservices' }
  s.platform     = :ios, '8.0'
  s.source       = { :git => 'https://github.com/qiniu-mob/qiniu-mob-ios.git',
                     :tag => s.version}
  s.libraries    = 'objc'
  s.requires_arc = true

  s.source_files = 'QNMob/include/**/*.{h,m}'
  s.public_header_files = 'QNMob/include/**/*.h'
  s.vendored_libraries = 'QNMob/**/*.a'
end
