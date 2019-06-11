import { BuildSystem } from 'cmake-js';

export interface CerberusBuilderOptions {
    runtime?: string;
    runtimeVersion?: string;
    arch?: string;
}

export async function CerberusBuild(options: CerberusBuilderOptions = {}) {
    const builder = new BuildSystem(<CerberusBuilderOptions>{
        runtime: process.env.CERBERUS_RUNTIME || 'electron',
        runtimeVersion: process.env.CERBERUS_RUNTIME_VERSION || '5.0.3',
        arch: process.env.CERBERUS_ARCH || 'ia64',
        ...options,
    });

    await builder.rebuild();
}