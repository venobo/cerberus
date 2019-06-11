const cmake = require('cmake-js');

const options = {
    runtime: process.env.CERBERUS_RUNTIME || 'electron',
    runtimeVersion: process.env.CERBERUS_RUNTIME_VERSION || '5.0.3',
    arch: process.env.CERBERUS_ARCH|| 'ia64',
};

const bs = new cmake.BuildSystem(options);
bs.rebuild();